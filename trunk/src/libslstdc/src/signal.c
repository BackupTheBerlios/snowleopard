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
// signal.c
//------------------------------------------------------------------------------
// Standard signal implementation
//------------------------------------------------------------------------------

#include <signal.h>
#include <stdlib.h>

#include <config/os_fixinclude.h>

#include sl_os_fixinclude(sys/types.h)
#include <unistd.h>

//------------------------------------------------------------------------------
// Private functions
int kill(pid_t pid, int sig);
void default_sighandler(int sig);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// signal function
sighandler_t signal(int sig, sighandler_t sigfunc) {
  if(sigfunc == NULL)
    return &default_sighandler;

  return sigfunc;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// raise function
int raise(int sig) {
  return kill(getpid(), sig);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// kill function
int kill(pid_t pid, int sig) {
  /* <TODO>: Implement kill */
  return EXIT_FAILURE;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// default_sighandler function
void default_sighandler(int sig) {

}
//------------------------------------------------------------------------------

//-<EOF>
