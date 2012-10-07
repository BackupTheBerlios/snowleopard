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
// cstdlib.cpp
//------------------------------------------------------------------------------
// Standard cstdlib implementation
//------------------------------------------------------------------------------

#include <sl/config/os_fixinclude.h>

#include <cstddef>
#include <cstdlib>

#include sl_os_fixinclude(unistd.h)

//------------------------------------------------------------------------------
// register for atexit function
namespace std {

namespace detail {

  static int n_atexit_functions = 0;
  static void (*atexit_functions[__SL_STDC_MAX_ATEXIT_FUNCTIONS])();

} //std::detail

} //std
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// exit function
void std::exit(int status)
{
  using std::detail::n_atexit_functions;
  using std::detail::atexit_functions;

  // TODO: Implement exit

  // Call functions registered by atexit in reverse order
  for(int i = std::detail::n_atexit_functions; i > 0; --i)
    (*std::detail::atexit_functions[i])();

  ::_exit(status);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// _Exit function
void std::_Exit(int status)
{
  ::_exit(status);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// abort function
void std::abort()
{
  while(1)
    ; /* Wait forever */
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// atexit function
int std::atexit(void (*function)())
{
  using std::detail::atexit_functions;
  using std::detail::n_atexit_functions;

  if(n_atexit_functions < __SL_STDC_MAX_ATEXIT_FUNCTIONS)
    atexit_functions [n_atexit_functions++] = function;
  else
    return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

//-<EOF>
