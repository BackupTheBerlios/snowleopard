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
// stdio_char_io.c
//------------------------------------------------------------------------------
// Standard input/output implementation: character input output functions
//
// Functions: fgetc
//            fgets
//            getc
//            getchar
//            fputc
//            fputs
//            putc
//            putchar
//            puts
//            ungetc
//------------------------------------------------------------------------------

#include <sl/config/config.h>

#include <sl/stdc/private/program_globals.h>

#include <errno.h>
#include <stdio.h>

#include <sl/config/os_fixinclude.h>

#include sl_os_fixinclude(fcntl.h)
#include sl_os_fixinclude(unistd.h)

//------------------------------------------------------------------------------
// fgetc function
int fgetc(FILE* stream) {

  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// fgets function
char* fgets(char* restrict s, int n, FILE* restrict stream) {
  
  return s;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// getc function
int getc(FILE* stream) {

  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// getchar function
int getchar() {

  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// fputc function
int fputc(int c, FILE* stream) {

  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// fputs function
int fputs(const char* restrict s, FILE* restrict stream) {

  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// putc function
int putc(int c, FILE* stream) {

  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// putchar function
int putchar(int c) {

  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// puts function
int puts(const char* s) {

  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ungetc function
int ungetc(int c, FILE* stream) {

  return 0;
}
//------------------------------------------------------------------------------

//-<EOF>
