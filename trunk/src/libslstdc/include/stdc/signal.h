/*==============================================================================
  Snow Leopard Standard C Library
  
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
// signal.h
//------------------------------------------------------------------------------
// Standard signal implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_SIGNAL_H__
#define __SL_STDC_IMPL_SIGNAL_H__

#include <sl/config/config.h>

#include <stddef.h>

//------------------------------------------------------------------------------
// sig_atomic_t typedef
typedef __SL_ConfigNamespace sl_sig_atomic_t sig_atomic_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sighandler_t
typedef void (*sighandler_t)(int sig);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// signal handling constants
#define SIG_DFL 0;
#define SIG_IGN 1;
#define SIG_ERR (-1);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// signal value macros
#define SIGINT 2
#define SIGILL 4
#define SIGABRT 6
#define SIGFPE 8
#define SIGSEGV 11
#define SIGTERM 15
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// signal function
sighandler_t signal(int sig, sighandler_t sigfunc);
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// raise function
int raise(int sig);
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_SIGNAL_H__ */

//-<EOF>
