/*
  Copyright 2015-2016 Hewlett Packard Enterprise Development LP
  
  This program is free software; you can redistribute it and/or modify 
  it under the terms of the GNU General Public License, version 2 as 
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, 
  but WITHOUT ANY WARRANTY; without even the implied warranty of 
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU General Public License for more details.

  You should have received a copy of the GNU General Public License 
  along with this program; if not, write to the Free Software 
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

*/
#include <crsmatrix.h>

extern mcrs_err mcrs_i_init(matrix_crs_i *m, i_t empty) {
	m->allocd_row = 0;
	m->allocd_col = 0;
	m->empty = empty;
	m->n_row = 0;
	m->n_col = 0;
	m->sz_row = 0;
	m->sz_col = 0;
	
	m->values = malloc(sizeof(m->values));
	m->col_ind = malloc(sizeof(m->col_ind));
	m->row_ptr = malloc(sizeof(m->row_ptr));
	
	if(m->values && m->col_ind && m->row_ptr)
		return MCRS_ERR_NONE;
	else
		return MCRS_ERR_UNABLE_TO_ALLOC;
}

extern mcrs_err mcrs_f_init(matrix_crs_f *m, f_t empty) {
	m->allocd_row = 0;
	m->allocd_col = 0;
	m->empty = empty;
	m->n_row = 0;
	m->n_col = 0;
	m->sz_row = 0;
	m->sz_col = 0;
	
	m->values = malloc(sizeof m->values);
	m->col_ind = malloc(sizeof m->col_ind);
	m->row_ptr = malloc(sizeof m->row_ptr);
	
	if(m->values && m->col_ind && m->row_ptr)
		return MCRS_ERR_NONE;
	else
		return MCRS_ERR_UNABLE_TO_ALLOC;
}

extern mcrs_err mcrs_i_free(matrix_crs_i *m) {
	m->allocd_row = 0;
        m->allocd_col = 0;
	m->empty = 0;
	m->sz_row = 0;
	m->sz_col = 0;
	
	free(m->values);
	free(m->col_ind);
	free(m->row_ptr);
	
	free(m);
	
	return MCRS_ERR_NONE;
}

extern mcrs_err mcrs_f_free(matrix_crs_f *m) {
        m->allocd_row = 0;
        m->allocd_col = 0;
	m->empty = 0;
        m->sz_row = 0;
        m->sz_col = 0;

        free(m->values);
        free(m->col_ind);
        free(m->row_ptr);

        return MCRS_ERR_NONE;
}

extern i_t mcrs_i_get(const matrix_crs_i *m, size_t x, size_t y) {
	if(y > m->sz_row)
		return m->empty;
	
	size_t ri = m->row_ptr[y];
	size_t ri_n = ((y + 1 < m->sz_row) ? m->row_ptr[y + 1] : m->sz_col); 

	if(ri == ri_n)
		return m->empty;
	
	size_t ci = 0;
	int found = 0;	
	
	for(ci = ri; ci < ri_n; ci++) {
		if(m->col_ind[ci] == x) {
			found = 1;
			break;
		}
	}

	if(!found)
		return m->empty;
	else
		return m->values[ci];
}

extern f_t mcrs_f_get(const matrix_crs_f *m, size_t x, size_t y) {
	if(y >= m->sz_row)
                return m->empty;

        size_t ri = m->row_ptr[y];
        size_t ri_n = ((y + 1 < m->sz_row) ? m->row_ptr[y + 1] : m->sz_col);

        if(ri == ri_n)
                return m->empty;

        size_t ci = 0;
        int found = 0;

        for(ci = ri; ci < ri_n; ci++) {
                if(m->col_ind[ci] == x) {
                        found = 1;
			break;
		}
        }

        if(!found)
                return m->empty;
        else
                return m->values[ci];
}

// FIX THIS
extern mcrs_err mcrs_i_set(matrix_crs_i *m, size_t x, size_t y, i_t val, mcrs_set_mode md) {
	m->n_row = ((y + 1) > m->n_row ? (y + 1) : m->n_row);
	m->n_col = ((x + 1) > m->n_col ? (x + 1) : m->n_col);
	
	if(val == m->empty)
		return MCRS_ERR_NONE;

	size_t ci = 0;
	size_t ci_n = 0;
	int newrow = 0;
	int newcol = 0;
	int found = 0;

	int ri_old;
	
	if(y >= m->sz_row) { // resize row_ptr
		if(y >= m->allocd_row) {
			while(y >= m->allocd_row) {
				m->allocd_row += MCRS_ALLOC_BLOCK;
			}
			
			m->row_ptr = realloc(m->row_ptr, sizeof(m->row_ptr) * m->allocd_row);
		}
		
		ri_old = m->sz_row;

		m->sz_row = y + 1;
	
		for(; ri_old < y; ri_old++) {
			m->row_ptr[ri_old] = m->sz_col;
		}
		
		if(m->row_ptr == NULL) {
			logd_e("ERROR: row_ptr = null sz_row=%d\n", m->sz_row);
			return MCRS_ERR_UNABLE_TO_ALLOC;
		}

		ci = m->sz_col;
		
		m->row_ptr[y] = ci;
		
		newrow = 1;
		found = 1;
	}
	else {
		ci = m->row_ptr[y];
		ci_n = (y + 1 >= m->sz_row ? m->sz_col : m->row_ptr[y + 1]);
		
		if(ci == ci_n)
			return MCRS_ERR_NONE;
	}

	if(!found) {
		for(; ci < ci_n; ci++) {
			if((m->col_ind[ci]) == x) {
				found = 1;
				break;
			}
		}
	}
	
	if(!found || newrow) { // resize col_ind
		if(!newrow && m->col_ind[m->sz_col - 1] > x) {
			logd_e("ERROR: no seq access on rows!\n");
			return MCRS_ERR_NO_SEQ_ACCESS;
		}

		if((m->sz_col + 1) > m->allocd_col) {
			m->col_ind = realloc(m->col_ind, sizeof(m->col_ind) * (m->allocd_col += MCRS_ALLOC_BLOCK));
			m->values = realloc(m->values, sizeof(m->values) * (m->allocd_col));
		}

		if(m->col_ind == NULL) {
			logd_e("ERROR: col_ind = null sz_col=%d\n", m->sz_col);
			return MCRS_ERR_UNABLE_TO_ALLOC;
		}
		if(m->values == NULL) {
			logd_e("ERROR: values = null sz_col=%d\n", m->sz_col);
                        return MCRS_ERR_UNABLE_TO_ALLOC;			
		}
	
		ci = m->sz_col;
		m->col_ind[ci] = x;
		
		m->sz_col++;

		newcol = 1;
	}

	if(md == MCRS_SET || newcol)
		m->values[ci] = val;
	else {
		if(md == MCRS_ADD)
			m->values[ci] += val;
		else if(md == MCRS_SUB)
			m->values[ci] -= val;
		else
			return MCRS_ERR_INVALID_MODE;	
	}
	
	return MCRS_ERR_NONE;
}

extern mcrs_err mcrs_f_set(matrix_crs_f *m, size_t x, size_t y, f_t val, mcrs_set_mode md) {
	m->n_row = ((y + 1) > m->n_row ? (y + 1) : m->n_row);
        m->n_col = ((x + 1) > m->n_col ? (x + 1) : m->n_col);

        if(val == m->empty)
                return MCRS_ERR_NONE;

        size_t ci = 0;
        size_t ci_n = 0;
        int newrow = 0;
        int newcol = 0;
        int found = 0;

        int ri_old;

        if(y >= m->sz_row) { // resize row_ptr
                if(y >= m->allocd_row) {
			while(y >= m->allocd_row) {
				m->allocd_row += MCRS_ALLOC_BLOCK;
			}
			
                        m->row_ptr = realloc(m->row_ptr, sizeof(m->row_ptr) * m->allocd_row);
			logd(LOGD_L, " row_ptr reallocd to %d\n", m->allocd_row);
                }

                ri_old = m->sz_row;

                m->sz_row = y + 1;

                for(; ri_old < y; ri_old++) {
                        m->row_ptr[ri_old] = m->sz_col;
                }

                if(m->row_ptr == NULL) {
                        logd_e("ERROR: row_ptr = null sz_row=%d\n", m->sz_row);
                        return MCRS_ERR_UNABLE_TO_ALLOC;
                }

                ci = m->sz_col;

                m->row_ptr[y] = ci;

                newrow = 1;
                found = 1;
        }
        else {
                ci = m->row_ptr[y];
                ci_n = (y + 1 >= m->sz_row ? m->sz_col : m->row_ptr[y + 1]);

                if(ci == ci_n)
                        return MCRS_ERR_NONE;
        }

        if(!found) {
                for(; (ci < ci_n); ci++) {
                        if((m->col_ind[ci]) == x) {
				found = 1;
                                break;
                        }
                }
        }
	
	if(!found || newrow) { // resize col_ind
                if(!newrow && m->col_ind[m->sz_col - 1] > x) {
                        logd_e("ERROR: no seq access on rows!\n");
                        return MCRS_ERR_NO_SEQ_ACCESS;
                }

                if((m->sz_col + 1) > m->allocd_col) {
                        m->col_ind = realloc(m->col_ind, sizeof(m->col_ind) * (m->allocd_col += MCRS_ALLOC_BLOCK));
                        m->values = realloc(m->values, sizeof(m->values) * (m->allocd_col));
			
			logd(LOGD_L, " col_ind, values reallocd to %d\n", m->allocd_col);
                }

                if(m->col_ind == NULL) {
                        logd_e("ERROR: col_ind = null sz_col=%d\n", m->sz_col);
                        return MCRS_ERR_UNABLE_TO_ALLOC;
                }
                if(m->values == NULL) {
                        logd_e("ERROR: values = null sz_col=%d\n", m->sz_col);
                        return MCRS_ERR_UNABLE_TO_ALLOC;
                }

                ci = m->sz_col;
                m->col_ind[ci] = x;

                m->sz_col++;

                newcol = 1;
        }

        if(md == MCRS_SET || newcol)
                m->values[ci] = val;
        else {
                if(md == MCRS_ADD)
			m->values[ci] = m->values[ci] + val;
                else if(md == MCRS_SUB)
                        m->values[ci] -= val;
                else
                        return MCRS_ERR_INVALID_MODE;
        }

        return MCRS_ERR_NONE;
}

extern mcrs_err mcrs_i_from_matrix_i(matrix_crs_i *dst, const matrix_i *src) {
	mcrs_err e;
	
	for(size_t i = 0; i < src->size; i++)
		for(size_t j = 0; j < src->size; j++)
			if((e = mcrs_i_set(dst, i, j, src->elements[i][j], MCRS_SET)) != MCRS_ERR_NONE)
				return e;
				
	return MCRS_ERR_NONE;
}

extern mcrs_err matrix_f_from_mcrs_i(matrix_f *dst, const matrix_crs_i *src) {
	int sz = (src->n_col > src->n_row) ? src->n_col : src->n_row;
	
	matrix_f_init_set(dst, sz, (float)src->empty);
	
	int i, j;
	for(i = 0; i < sz; i++)
		for(j = 0; j < sz; j++)
			dst->elements[i][j] = (float)mcrs_i_get(src, i, j);
	
	return MCRS_ERR_NONE;
}

extern mcrs_err matrix_f_from_mcrs_f(matrix_f *dst, const matrix_crs_f *src) {
	int sz = (src->n_col > src->n_row) ? src->n_col : src->n_row;

        matrix_f_init_set(dst, sz, (float)src->empty);

        int i, j;
        for(i = 0; i < sz; i++)
                for(j = 0; j < sz; j++)
                        dst->elements[i][j] = (float)mcrs_f_get(src, i, j);

        return MCRS_ERR_NONE;
}

extern mcrs_err mcrs_i_load(matrix_crs_i *m, const char *path, const char col, const char row) {
	FILE *f = fopen(path, "rb");
	
	if(!f)
		return MCRS_ERR_UNABLE_TO_OPEN_FILE;
	
	mcrs_err e;
	
	char *buffer = 0;
	long length = 0;

	fseek(f, 0, SEEK_END);
	length = ftell(f);
	rewind(f);
	
	if(length <= 0)
		return MCRS_ERR_INVALID_FILE;
	
	buffer = calloc(length + 1, 1);
	
	if(buffer == NULL)
		return MCRS_ERR_UNABLE_TO_ALLOC;
	
	length = fread(buffer, 1, length, f);
	buffer[++length] = '\0';
	
	char *el1 = 0;
	char *el2 = 0;
	int i1 = 0;
	int i2 = 0;
	
	el1 = strtok(buffer, &col);

	if(el1 == NULL)
		return MCRS_ERR_INVALID_FILE;
	
	while(el1) {
		el2 = strtok(NULL, &row);
		
		if(el2 == NULL)
			return MCRS_ERR_INVALID_FILE;
	
		i1 = atoi(el1);
		i2 = atoi(el2);

		if((e = mcrs_i_set(m, i2, i1, 1, MCRS_ADD)) != MCRS_ERR_NONE) {
			logd_e(" An error occured while setting i1(row)=%d i2(col)=%d: %d\n", i1, i2, e);
			return e;
		}
	
		el1 = strtok(NULL, &col);
	}

	free(buffer);
	
	return MCRS_ERR_NONE;
}

extern mcrs_err mcrs_f_load(matrix_crs_f *m, const char *path, const char col, const char row) {
	FILE *f = fopen(path, "rb");

        if(!f)
                return MCRS_ERR_UNABLE_TO_OPEN_FILE;

        mcrs_err e;

        char *buffer = 0;
        long length = 0;

        fseek(f, 0, SEEK_END);
        length = ftell(f);
        rewind(f);

        if(length <= 0)
                return MCRS_ERR_INVALID_FILE;

        buffer = calloc(length + 1, 1);

        if(buffer == NULL)
                return MCRS_ERR_UNABLE_TO_ALLOC;

        length = fread(buffer, 1, length, f);
        buffer[++length] = '\0';

        char *el1 = 0;
        char *el2 = 0;
        int i1 = 0;
        int i2 = 0;

        el1 = strtok(buffer, &col);

        if(el1 == NULL)
                return MCRS_ERR_INVALID_FILE;

        while(el1) {
                el2 = strtok(NULL, &row);

                if(el2 == NULL)
                        return MCRS_ERR_INVALID_FILE;

                i1 = atof(el1);
                i2 = atof(el2);

                if((e = mcrs_f_set(m, i2, i1, 1.0, MCRS_ADD)) != MCRS_ERR_NONE) {
                        logd_e(" An error occured while setting i1(row)=%d i2(col)=%d: %d\n", i1, i2, e);
                        return e;
                }

                el1 = strtok(NULL, &col);
        }

	free(buffer);
	
        return MCRS_ERR_NONE;
}

//extern i_t mcrs_i_get(
