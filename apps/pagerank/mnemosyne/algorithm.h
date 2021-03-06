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
#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "crsmatrix.h"

#include "vector.h"
#include "logger.h"

#include <pthread.h>

typedef struct thd_data {
	int thread_id;
	mcrs_err e;
	
	logd_lvl_t lvl;
	l_clock_t* tmr;
	
	vector_f *out;
	vector_f *loc;
	matrix_crs_f *m;
	vector_f *v;
	
	size_t rstart;
	size_t rend;
} thd_data_t;

extern mcrs_err mcrs_gmatrix_mult_vector_f_mt(logd_lvl_t lvl, vector_f *out, const matrix_crs_f *m, const vector_f *v, const size_t n_threads, const size_t n_iterations);

extern mcrs_err mcrs_gmatrix_mult_vector_f(vector_f *out, const matrix_crs_f *m, const vector_f *v);
mcrs_err mcrs_gmatrix_mult_vector_f_rng(vector_f *out, const matrix_crs_f *m, const vector_f *v, const size_t rstart, const size_t rend, const int thd_enabled);

extern mcrs_err check_gmatrix_integrity(const logd_lvl_t lvl, const matrix_crs_f *m);

extern void gen_link_vector_crs(vector_i *linkv, int* empty, const matrix_crs_f *adjm);

extern void gen_google_matrix_crs(matrix_crs_f *m, const vector_i *linkv, const float damping_factor);

#endif // ALGORITHM_H
