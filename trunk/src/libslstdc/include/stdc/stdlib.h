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
// stdlib.h
//------------------------------------------------------------------------------
// Standard library implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_STDLIB_H__
#define __SL_STDC_IMPL_STDLIB_H__

#include "stdc/config_stdc.h"

#include "stdc/private/shared_types.h"

//------------------------------------------------------------------------------
// div_t struct
struct div_t {
  int quot;
  int rem;
};

typedef struct div_t div_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ldiv_t struct
struct ldiv_t {
  long quot;
  long rem;
};

typedef struct ldiv_t ldiv_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lldiv_t struct
struct lldiv_t {
  long long quot;
  long long rem;
};

typedef struct lldiv_t lldiv_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// exit status
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// RAND_MAX macro
#define RAND_MAX SL_INT_MAX
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// MB_CUR_MAX macro
#define MB_CUR_MAX SL_WCHAR_MAX_BYTES
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Numeric conversion functions
//
// ato functions
double atof(const char* nptr);
int atoi(const char* nptr);
long atol(const char* nptr);
long long atoll(const char* nptr);
// strto functions
double strtod(const char* restrict nptr, char** restrict endptr);
float strtof(const char* restrict nptr, char** restrict endptr);
long double strtold(const char* restrict nptr, char** restrict endptr);
long strtol(const char* restrict nptr, char** restrict endptr, int base);
long long strtoll(const char* restrict nptr, char** restrict endptr, int base);
unsigned long strtoul(
    const char* restrict nptr,
    char** restrict endptr,
    int base
                      );
unsigned long long strtoull(
    const char* restrict nptr,
    char** restrict endptr,
    int base
                            );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Pseudo-random sequence generation functions
int rand();
void srand(unsigned int seed);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Memory management functions
void* aligned_alloc(size_t alignment, size_t size);
void* calloc(size_t nmemb, size_t size);
void free(void* ptr);
void* malloc(size_t size);
void* realloc(void* ptr, size_t size);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Communication with the environment
_Noreturn void abort();
int atexit(void (* function)());
int at_quick_exit(void (* function)());
_Noreturn void exit(int status);
_Noreturn void _Exit(int status);
char* getenv(const char* name);
_Noreturn void quick_exit(int status);
int system(const char* string);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Searching and sorting functions
void* bsearch(
    const void* key,
    const void* base,
    size_t nmemb,
    size_t size,
    int (*compar)(const void*, const void*)
              );
void qsort(
    void* base,
    size_t nmemb,
    size_t size,
    int (*compar)(const void*, const void*)
           );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Integer arithmetic functions
//
// abs functions
int abs(int j);
long labs(long j);
long long llabs(long long j);
// div functions
div_t div(int numer, int denom);
ldiv_t ldiv(long numer, long denom);
lldiv_t lldiv(long long numer, long long denom);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Multibyte/wide character conversion functions
int mblen(const char* s, size_t n);
int mbtowc(wchar_t* restrict pwc, const char* restrict s, size_t n);
int wctomb(char* s, wchar_t wc);
size_t mbstowcs(wchar_t* restrict pwcs, const char* restrict s, size_t n);
size_t wcstombs(char* restrict s, const wchar_t* restrict pwvs, size_t n);
//------------------------------------------------------------------------------

//==============================================================================
// Bounds checking functions
#if __STDC_WANT_LIB_EXT1__ == 1
# include <errno.h>
//------------------------------------------------------------------------------
// constraint_handler_t type
typedef void (*constraint_handler_t) (
    const char* restrict msg,
    void* restrict ptr,
    errno_t error
                                      );  
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Runtime constraint handling functions
constraint_handler_t set_constraint_handler_s(
    constraint_handler_t handler
                                              );
void abort_handler_s(
    const char* restrict msg, 
    void* restrict ptr, 
    errno_t error
                     );
void ignore_handler_s(
    const char* restrict msg,
    void* restrict ptr,
    errno_t error
                      );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Communication with environment functions
errno_t getenv_s(
    size_t* restrict len,
    char* restrict value,
    rsize_t maxsize,
    const char* restrict name
                 );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Searching and sorting functions
void* bsearch_s(
    const void* key,
    const void* base,
    rsize_t nmemb,
    rsize_t size,
    int (*compar)(const void* k, const void *y, void* context),
    void* context
                );
errno_t qsort_s(
    void* base,
    rsize_t nmemb,
    rsize_t size,
    int (*compar)(const void* k, const void *y, void* context),
    void* context
                );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Multibyte/wide character conversion functions
errno_t wctomb_s(
    int* restrict status, 
    char* restrict s, 
    rsize_t smax, 
    wchar_t wc
                 );
errno_t mbstowcs_s(
    size_t* restrict retval,
    wchar_t* restrict dst,
    rsize_t dstmax,
    const char* restrict src,
    rsize_t len
                   );
errno_t wcstombs_s(
    size_t* restrict retval,
    char* restrict dst,
    rsize_t dstmax,
    const wchar_t* restrict src,
    rsize_t len
                   );
//------------------------------------------------------------------------------
#endif /* __STDC_WANT_LIB_EXT1__ == 1 */
//==============================================================================

//==============================================================================
// Non standard features
#ifdef __SL_ENABLE_NON_STANDARD_FEATURES
# include <stdc/stdlib_no_stdc.h>
#endif /* __SL_ENABLE_NON_STANDARD_FEATURES */
//==============================================================================

#endif /* !__SL_STDC_IMPL_STDLIB_H__ */

//-<EOF>
