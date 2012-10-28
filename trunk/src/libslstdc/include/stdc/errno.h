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
// errno.h
//------------------------------------------------------------------------------
// Standard error handling implementation
//------------------------------------------------------------------------------

#ifndef _SL_STDC_IMPL_ERRNO_H_
#define _SL_STDC_IMPL_ERRNO_H_

#include "stdc/config_stdc.h"

//------------------------------------------------------------------------------
// errno_t type
typedef __SL_ConfigNamespace sl_errno_t errno_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error macros.
#define EAFNOSUPPORT    1
#define EADDRINUSE      2
#define EADDRNOTAVAIL   3
#define EISCONN         4
#define E2BIG           5
#define EDOM            6
#define EFAULT          7
#define EBADF           8
#define EBADMSG         9
#define EPIPE           10
#define ECONNABORTED    11
#define EALREADY        12
#define ECONNREFUSED    13
#define ECONNRESET      14
#define EXDEV           15
#define EDESTADDRREQ    16
#define EBUSY           17
#define ENOTEMPTY       18
#define ENOEXEC         19
#define EEXIST          20
#define EFBIG           21
#define ENAMETOOLONG    22
#define ENOSYS          23
#define EHOSTUNREACH    24
#define EIDRM           25
#define EILSEQ          26
#define ENOTTY          27
#define EINTR           28
#define EINVAL          29
#define ESPIPE          30
#define EIO             31
#define EISDIR          32
#define EMSGSIZE        33
#define ENETDOWN        34
#define ENETRESET       35
#define ENETUNREACH     36
#define ENOBUFS         37
#define ECHILD          38
#define ENOLINK         39
#define ENOLCK          40
#define ENODATA         41
#define ENOMSG          42
#define ENOPROTOOPT     43
#define ENOSPC          44
#define ENOSR           45
#define ENXIO           46
#define ENODEV          47
#define ENOENT          48
#define ESRCH           49
#define ENOTDIR         50
#define ENOTSOCK        51
#define ENOSTR          52
#define ENOTCONN        53
#define ENOMEM          54
#define ENOTSUP         55
#define ECANCELED       56
#define EINPROGRESS     57
#define EPERM           58
#define EOPNOTSUPP      59
#define EWOULDBLOCK     60
#define EOWNERDEAD      61
#define EACCES          62
#define EPROTO          63
#define EPROTONOSUPPORT 64
#define EROFS           65
#define EDEADLK         66
#define EAGAIN          67
#define ERANGE          68
#define ENOTRECOVERABLE 69
#define ETIME           70
#define ETXTBSY         71
#define ETIMEDOUT       72
#define ENFILE          73
#define EMFILE          74
#define EMLINK          75
#define ELOOP           76
#define EOVERFLOW       77
#define EPROTOTYPE      78
#define ELAST           79
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// errno variable.
extern errno_t errno;
//------------------------------------------------------------------------------

#endif /* !_SL_STDC_IMPL_ERRNO_H_ */

//-<EOF>
