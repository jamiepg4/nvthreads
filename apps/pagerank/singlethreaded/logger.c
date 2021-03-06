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
#include <logger.h>

/* --- LOG --- */

logd_lvl_t logd_level;

extern void logd_set_level(logd_lvl_t lvl) {
	logd_level = (lvl < LOGD_NONE) ? lvl : LOGD_NONE;
}

extern void logd(logd_lvl_t lvl, const char *format, ...) {
	if(lvl >= logd_level && lvl < LOGD_NONE) {
		va_list args;
		va_start(args, format);

		vprintf(format, args);
		fflush(stdout);

		va_end(args);
	}
}

extern void logd_e(const char *format, ...) {
	va_list args;
	va_start(args, format);
	
	vfprintf(stderr, format, args);
	fflush(stderr);	

	va_end(args);
}

/* --- TIMER ---  */
const l_time_t _TMR_NS_IN_MS = 1000000L; 
const clockid_t _TMR_T = CLOCK_REALTIME;

extern struct timespec* timer_alloc() {
	return (struct timespec*)malloc(sizeof(struct timespec));
}

extern void timer_start(struct timespec *tmr) {
	clock_gettime(_TMR_T, tmr);
}

extern l_time_t timer_total(struct timespec *tmr) {
	struct timespec tmr_end;
	
	clock_gettime(_TMR_T, &tmr_end);
	
	return tmr_end.tv_nsec - tmr->tv_nsec;
}

extern l_time_t timer_total_ms(struct timespec *tmr) {
	return timer_total(tmr) / _TMR_NS_IN_MS;
}

extern l_time_t timer_lap(struct timespec *tmr) {
	l_time_t time = timer_total(tmr);
	
	clock_gettime(_TMR_T, tmr);
	
	return time;
}

extern l_time_t timer_lap_ms(struct timespec *tmr) {
	return timer_lap(tmr) / _TMR_NS_IN_MS;
}

extern void timer_free(struct timespec *tmr) {
	free(tmr);
}
