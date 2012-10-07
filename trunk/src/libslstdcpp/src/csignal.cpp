/*==============================================================================
  Snow Leopard Standard C++ Library
  
  Copyright (C) 2008-2012 Roel Sergeant
  
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
// csignal.cpp
//------------------------------------------------------------------------------
// Standard csignal implementation
//------------------------------------------------------------------------------

#include <sl/config/os_fixinclude.h>

#include <csignal>
#include <cstdlib>

#include sl_os_fixinclude(/sys/types.h)
#include sl_os_fixinclude(unistd.h)

//------------------------------------------------------------------------------
// kill function
//
// NOTE: Private function.
//
int kill(pid_t pid, int signal) {
  // TODO: Implement kill
  return EXIT_FAILURE;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// signal function
// TODO: signal function

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// raise function
int std::raise(int signal) {
  return kill(getpid(), signal);
}
//------------------------------------------------------------------------------

//-<EOF>
