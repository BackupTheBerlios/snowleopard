/*==============================================================================
  Snow Leopard Standard C Library
  
  Copyright (C) 2008, 2012 Roel Sergeant
  
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
// run_1_setjmp_1.c
//------------------------------------------------------------------------------
// Tests for setjmp header. Possible memory leak.
//------------------------------------------------------------------------------

#include <setjmp.h>

jmp_buf buf;
int n = 6;

void f() {
  int x[n];
  setjmp(buf);
  g(n);
}

void g() {
  int a[n];
  h(n);
}

void h() {
  int b[n];
  longjmp(buf, 2);
}

int main () {
  f();

  return 0;
}

//-<EOF>
