/*==============================================================================
  Snow Leopard Standard C Library
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
  This program is free software: you can redistribute it and/or modify it under
  the terms of the GNU General Public License as published by the Free
  Software Foundation, either version 3 of the License, or (at your option) any
  later version
  
  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
  FOR A PARTICULAR PURPOSE. See the GNU General Public License for more 
  details.
  
  You should have received a copy of the GNU General Public License along with
  this program. If not, see <http://www.gnu.org/licenses/>
  ============================================================================*/

//------------------------------------------------------------------------------
// time.h
//------------------------------------------------------------------------------
// Standard time implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_TIME_H__
#define __SL_STDC_IMPL_TIME_H__

#include "stdc/config_stdc.h"

#include "stdc/private/shared_types.h"

//------------------------------------------------------------------------------
// Macros
//
#define CLOCKS_PER_SEC SL_CLOCKS_PER_SEC
#define UTC_TIME SL_UTC_TIME
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// clock_t type
//
typedef __SL_ConfigNamespace sl_clock_t clock_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// time_t type
//
typedef __SL_ConfigNamespace sl_time_t time_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// timespec struct
//
struct timespec 
{
  time_t tv_sec;
  long tv_nsec;
};

typedef struct timespec timespec;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// tm struct
//
struct tm 
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst; /* + is DST in effect; 0 is not in effect; - is unknown */
};

typedef struct tm tm;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Time manipulation functions
//
clock_t clock();
double difftime(time_t time1, time_t time0);
time_t mktime(tm* timeptr);
time_t time(time_t* timer);
int timespec_get(timespec* ts, int base);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Time conversion functions
//
char* asctime(const tm* timeptr);
char* ctime(const time_t* timer);
tm* gmtime(const time_t* timer);
tm* localtime(const time_t* timer);
size_t strftime(
    char* restrict s,
    size_t maxsize,
    const char* restrict format,
    const tm* restrict timeptr
                );
//------------------------------------------------------------------------------

//==============================================================================
// Bounds checking functions
//
#if __STDC_WANT_LIB_EXT1__ == 1

//------------------------------------------------------------------------------
// Time conversion functions
//
errno_t asctime_s(char* s, rsize_t maxsize, const tm* timeptr);
errno_t ctime_s(char* s, rsize_t maxsize, const time_t* timer);
tm* gmtime_s(const time_t* restrict timer, tm* restrict result);
tm* localtime_s(const time_t* restrict timer, tm* restrict result);
//------------------------------------------------------------------------------

#endif /* __STDC_WANT_LIB_EXT1__ == 1 */
//==============================================================================

#endif /* !__SL_STDC_IMPL_TIME_H__ */

//-<EOF>
