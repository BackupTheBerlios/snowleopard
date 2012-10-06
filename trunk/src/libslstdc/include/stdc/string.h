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
// string.h
//------------------------------------------------------------------------------
// Standard string implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_STRING_H__
#define __SL_STDC_IMPL_STRING_H__

#include <config/config.h>

#include <stddef.h>

//------------------------------------------------------------------------------
// Copy and move functions
void* memcpy(void* restrict s1, const void* restrict s2, size_t n);
void* memmove(void* s1, const void* s2, size_t n);
char* strcpy(char* restrict s1, const char* restrict s2);
char* strncpy(char* restrict s1, const char* restrict s2, size_t n);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Concatenation functions
char* strcat(char* restrict s1, const char* restrict s2);
char* strncat(char* restrict s1, const char* restrict s2, size_t n);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// String comparison functions
int memcmp(const void* s1, const void* s2, size_t n);
int strcmp(const char* s1, const char* s2);
int strcoll(const char* s1, const char* s2, size_t n);
int strncmp(const char* s1, const char* s2, size_t n);
size_t strxfrm(char* restrict s1, const char* restrict s2, size_t n);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Search functions
void* memchr(const void* s, int c, size_t n);
char* strchr(const char* s, int c);
size_t strcspn(const char* s1, const char* s2);
char* strpbrk(const char* s1, const char* s2);
char* strrchr(const char* s, int c);
size_t strspn(const char* s1, const char* s2);
char* strstr(const char* s1, const char* s2);
char* strtok(char* restrict s1, const char* restrict s2);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Miscellaneous functions
void* memset(void* s, int c, size_t n);
char* strerror(int errnum);
size_t strlen(const char* s);
//------------------------------------------------------------------------------

//==============================================================================
// Bounds checking functions
#if __STDC_WANT_LIB_EXT1__ == 1
# include <errno.h>
//------------------------------------------------------------------------------
// Copying functions
errno_t memcpy_s(
    void* restrict s1, 
    rsize_t s1max, 
    const void* restrict s2,
    rsize_t n
                 );
errno_t memmove_s(void* s1, rsize_t s1max, const void* s2, rsize_t n);
errno_t strcpy_s(char* restrict s1, rsize_t s1max, const char* restrict s2);
errno_t strncpy_s(
    char* restrict s1,
    rsize_t s1max,
    const char* restrict s2,
    rsize_t n
                  );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Concatenation functions
errno_t strcat_s(char* restrict s1, rsize_t s1max, const char* restrict s2);
errno_t strncat_s(
    char* restrict s1,
    rsize_t s1max,
    const char* restrict s2,
    rsize_t n
                  );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Search functions
char* strktok_s(
    char* restrict s1,
    rsize_t* restrict s1max,
    const char* restrict s2,
    char** restrict ptr
                );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Miscellaneous functions
errno_t memset_s(void* s, rsize_t smax, int c, rsize_t n);
errno_t strerror_s(char* s, rsize_t maxsize, errno_t errnum);
size_t strerrorlen_s(errno_t errnum);
size_t strnlen_s(const char* s,size_t maxsize);
//------------------------------------------------------------------------------
#endif /* __STDC_WANT_LIB_EXT1__ == 1 */
//==============================================================================

#endif /* !__SL_STDC_IMPL_STRING_H__ */

//-<EOF>
