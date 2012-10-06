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
// stdlib_env.c
//------------------------------------------------------------------------------
// Standard stdlib implementation
//------------------------------------------------------------------------------

#include <sl/config/config.h>

#include <signal.h>
#include <stddef.h>
#include <stdlib.h>

#include <sl/config/os_fixinclude.h>

#include sl_os_fixinclude(sys/types.h)
#include sl_os_fixinclude(unistd.h)

//------------------------------------------------------------------------------
// register for atexit function
static int n_atexit_functions = 0;
static void (* atexit_functions[__SL_STDC_MAX_ATEXIT_FUNCTIONS])();
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// exit function
void exit(int status) {
  // TODO: Closing all resources (files, sockets, ...)

  // Call functions registered by atexit in reverse order
  for (int i = n_atexit_functions; i > 0; --i)
    (*atexit_functions[i])();

  _exit(status);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// _Exit function
void _Exit(int status) {
  _exit(status);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// abort function
void abort() {
  raise(SIGABRT);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// atexit function
int atexit(void (* function)()) {
  if (n_atexit_functions < __SL_STDC_MAX_ATEXIT_FUNCTIONS)
    atexit_functions[n_atexit_functions++] = function;
  else
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//-<EOF>
