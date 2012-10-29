/*==============================================================================
  Snow Leopard Project
  
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
// config_errno.h
//------------------------------------------------------------------------------
// Configuration applicable to all complex number C code.
//    - lynx
//    - puma
//    - slcc
//    - slsh
//    - libslstdc
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_CONFIG_ERRNO_H__
#define __SL_CONFIG_CONFIG_ERRNO_H__

//------------------------------------------------------------------------------
// Error numbers
//
#define __SL_EAFNOSUPPORT    1
#define __SL_EADDRINUSE      2
#define __SL_EADDRNOTAVAIL   3
#define __SL_EISCONN         4
#define __SL_E2BIG           5
#define __SL_EDOM            6
#define __SL_EFAULT          7
#define __SL_EBADF           8
#define __SL_EBADMSG         9
#define __SL_EPIPE           10
#define __SL_ECONNABORTED    11
#define __SL_EALREADY        12
#define __SL_ECONNREFUSED    13
#define __SL_ECONNRESET      14
#define __SL_EXDEV           15
#define __SL_EDESTADDRREQ    16
#define __SL_EBUSY           17
#define __SL_ENOTEMPTY       18
#define __SL_ENOEXEC         19
#define __SL_EEXIST          20
#define __SL_EFBIG           21
#define __SL_ENAMETOOLONG    22
#define __SL_ENOSYS          23
#define __SL_EHOSTUNREACH    24
#define __SL_EIDRM           25
#define __SL_EILSEQ          26
#define __SL_ENOTTY          27
#define __SL_EINTR           28
#define __SL_EINVAL          29
#define __SL_ESPIPE          30
#define __SL_EIO             31
#define __SL_EISDIR          32
#define __SL_EMSGSIZE        33
#define __SL_ENETDOWN        34
#define __SL_ENETRESET       35
#define __SL_ENETUNREACH     36
#define __SL_ENOBUFS         37
#define __SL_ECHILD          38
#define __SL_ENOLINK         39
#define __SL_ENOLCK          40
#define __SL_ENODATA         41
#define __SL_ENOMSG          42
#define __SL_ENOPROTOOPT     43
#define __SL_ENOSPC          44
#define __SL_ENOSR           45
#define __SL_ENXIO           46
#define __SL_ENODEV          47
#define __SL_ENOENT          48
#define __SL_ESRCH           49
#define __SL_ENOTDIR         50
#define __SL_ENOTSOCK        51
#define __SL_ENOSTR          52
#define __SL_ENOTCONN        53
#define __SL_ENOMEM          54
#define __SL_ENOTSUP         55
#define __SL_ECANCELED       56
#define __SL_EINPROGRESS     57
#define __SL_EPERM           58
#define __SL_EOPNOTSUPP      59
#define __SL_EWOULDBLOCK     60
#define __SL_EOWNERDEAD      61
#define __SL_EACCES          62
#define __SL_EPROTO          63
#define __SL_EPROTONOSUPPORT 64
#define __SL_EROFS           65
#define __SL_EDEADLK         66
#define __SL_EAGAIN          67
#define __SL_ERANGE          68
#define __SL_ENOTRECOVERABLE 69
#define __SL_ETIME           70
#define __SL_ETXTBSY         71
#define __SL_ETIMEDOUT       72
#define __SL_ENFILE          73
#define __SL_EMFILE          74
#define __SL_EMLINK          75
#define __SL_ELOOP           76
#define __SL_EOVERFLOW       77
#define __SL_EPROTOTYPE      78
#define __SL_ELAST           79
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_CONFIG_ERRNO_H__ */

//-<EOF>

