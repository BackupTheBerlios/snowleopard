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
// stdio.h
//------------------------------------------------------------------------------
// Standard input/output implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_STDIO_H__
#define __SL_STDC_IMPL_STDIO_H__

#include "stdc/config_stdc.h"

#include "stdc/private/shared_macros.h"
#include "stdc/private/shared_types.h"

//------------------------------------------------------------------------------
// Include types
//
#include "stdc/stdio_types.h"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Buffer macros
//
#define _IOFBUF __SL__IOFIXEDBUF
#define _IOLBUF __SL__IOLINEBUF
#define _IONBUF __SL__IOUNBUF
#define BUFSIZE __SL_BUFFER_SIZE
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Stream macros
//
#define _IOREAD       __SL__IOREAD
#define _IOWRITE      __SL__IOWRITE
#define _IOREADAHEAD  __SL__IOREADAHEAD
#define _IOUNGETC     __SL__IOUNGETC
#define _IODIRTYBLOCK __SL__IODIRTYBLOCK
#define _IOEOF        __SL__IOEOF
#define _IOERROR      __SL__IOERROR
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Default permissions
//
#define _DEFAULT_PERMISSIONS 0666
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// File maxima
//
// EOF macro
//
#define EOF __SL_EOF
//
// Open files
//
#define FOPEN_MAX __SL_FOPEN_MAX
#define TMP_MAX __SL_TMP_MAX
#define TMP_MAX_S __SL_TMP_MAX_S
//
// Filenames
//
#define FILENAME_MAX __SL_FILENAME_MAX
#define L_tmpnam __SL_L_tmpnam
#define L_tmpnam_s __SL_L_tmpnam_s
//
// Seek directives
//
#define SEEK_CUR __SL_SEEK_CUR
#define SEEK_END __SL_SEEK_END
#define SEEK_SET __SL_SEEK_SET
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// TMP_MAX_S macro
//
#define TMP_MAX_S __SL_TMP_MAX_S
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Standard file streams
//
FILE* stderr;
FILE* stdin;
FILE* stdout;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// File operation functions
//
int remove(const char* filename);
int rename(const char*oldf, const char* newf);
FILE* tmpfile();
char* tmpnam(char* s);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// file access functions
//
int fclose(FILE* stream);
int fflush(FILE* stream);
FILE* fopen(const char* restrict filename, const char* restrict mode);
FILE* freopen(
              const char* restrict filename,
              const char* restrict mode,
              FILE* restrict stream
	      );
void setbuf(FILE* restrict stream, char* restrict buf);
int setvbuf(
	    FILE* restrict stream,
	    char* restrict buf,
	    int mode,
	    size_t size
	    );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Formatted input/output functions
// 
// printf functions
//
int fprintf(FILE* restrict stream, const char* restrict format, ...);
int printf(const char* restrict format, ...);
int snprintf(
	     const char* restrict s,
	     size_t n,
	     const char* restrict format,
	     ...
	     );
int sprintf(char* restrict s, const char* restrict format, ...);
int vfprintf(FILE* restrict stream, const char* restrict format, va_list arg);
int vprintf(const char* restrict format, va_list arg);
int vsnprintf(
	      const char* restrict s,
	      size_t n,
	      const char* restrict format,
	      va_list arg
	      );
int vsprintf(char* restrict s, const char* restrict format, va_list arg);
//
// scanf functions
//
int fscanf(FILE* restrict stream, const char* restrict format, ...);
int scanf(const char* restrict format, ...);
int sscanf(const char* restrict s, const char* restrict format, ...);
int vfscanf(
	    FILE* restrict stream,
	    const char* restrict format,
	    va_list arg
	    );
int vscanf(const char* restrict format);
int vsscanf(const char* restrict s, const char* restrict format, va_list arg);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Character input/output functions
//
// getc functions
//
int fgetc(FILE* stream);
char* fgets(char* restrict s, int n, FILE* restrict stream);
int getc(FILE* stream);
int getchar();
//
// putc functions
//
int fputc(int c, FILE* stream);
int fputs(const char* restrict s, FILE* restrict stream);
int putc(int c, FILE* stream);
int putchar(int c);
int puts(const char* s);
//
// ungetc function
//
int ungetc(int c, FILE* stream);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Direct input output functions
//
size_t fread(
	     void* restrict ptr, 
	     size_t size, 
	     size_t nmemb, 
	     FILE* restrict stream
             );
size_t fwrite(
	      const void* restrict ptr,
	      size_t size,
	      size_t nmemb,
	      FILE* restrict stream
              );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// File positioning functions
//
int fgetpos(FILE* restrict stream, fpos_t* restrict pos);
int fseek(FILE* stream, long offset, int whence);
int fsetpos(FILE* stream, const fpos_t* pos);
long ftell(FILE* stream);
void rewind(FILE* stream);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error handling functions
//
void clearerr(FILE* stream);
int feof(FILE* stream);
int ferror(FILE* stream);
void perror(const char* s);
//------------------------------------------------------------------------------

//==============================================================================
// Bound checking functions.
//
#if __STDC_WANT_LIB_EXT1__ == 1

//------------------------------------------------------------------------------
// File operation functions
//
errno_t tmpfile_s(FILE* restrict * restrict streamptr);
errno_t tmpname_s(char* s, rsize_t maxsize);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// File access functions
//
errno_t fopen_s(
		FILE* restrict * restrict streamptr,
		const char* restrict filename,
		const char* restrict mode
                );
errno_t freopen_s(
		  FILE* restrict * restrict newstreamptr,
		  const char* restrict filename,
		  const char* restrict mode,
		  FILE* restrict streamptr
                  );
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Formatted input/output functions
//
// printf functions
//
int fprintf_s(FILE* restrict stream, const char* restrict format, ...);
int printf_s(const char* restrict format, ...);
int snprintf_s(char* restrict s, rsize_t n, const char* restrict format, ...);
int sprintf_s(char* restrict s, rsize_t n, const char* restrict format, ...);
int vfprintf_s(FILE* restrict stream, const char* restrict format, va_list arg);
int vprintf_s(const char* restrict format, va_list arg);
int vsnprintf_s(
		char* restrict s,
		rsize_t n,
		const char* restrict format,
		va_list arg
                );
int vsprintf_s(
	       char* restrict s,
	       rsize_t n,
	       const char* restrict format,
	       va_list arg
               );
//
//scanf functions
//
int fscanf_s(FILE* restrict stream, const char* restrict format, ...);
int scanf_s(const char* restrict format, ...);
int sscanf_s(const char* restrict s, const char* restrict format, ...);
int vfscanf_s(FILE* restrict stream, const char* restrict format, va_list arg);
int vscanf_s(const char* restrict format, va_list arg);
int vsscanf_s(const char* restrict s, const char* restrict format, va_list arg);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Character input/output functions
//
// getc functions
//
char* gets_s(char* s, rsize_t n);
//------------------------------------------------------------------------------

#endif /* __STDC_WANT_LIB_EXT1__ == 1 */
//==============================================================================

#endif /* !__SL_STDC_IMPL_STDIO_H__ */

//-<EOF>
