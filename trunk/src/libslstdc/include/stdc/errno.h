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

#ifndef __SL_STDC_IMPL_ERRNO_H__
#define __SL_STDC_IMPL_ERRNO_H__

#include "stdc/config_stdc.h"

#include "stdc/private/shared_types.h"

//------------------------------------------------------------------------------
// errno_t type
//
// errno_t is defined in private/shared_types.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Error macros
//
#define EAFNOSUPPORT    __SL_EAFNOSUPPORT
#define EADDRINUSE      __SL_EADDRINUSE
#define EADDRNOTAVAIL   __SL_EADDRNOTAVAIL
#define EISCONN         __SL_EISCONN
#define E2BIG           __SL_E2BIG
#define EDOM            __SL_EDOM
#define EFAULT          __SL_EFAULT
#define EBADF           __SL_EBADF
#define EBADMSG         __SL_EBADMSG
#define EPIPE           __SL_EPIPE
#define ECONNABORTED    __SL_ECONNABORTED
#define EALREADY        __SL_EALREADY
#define ECONNREFUSED    __SL_ECONNREFUSED
#define ECONNRESET      __SL_ECONNRESET
#define EXDEV           __SL_EXDEV
#define EDESTADDRREQ    __SL_EDESTADDRREQ
#define EBUSY           __SL_EBUSY
#define ENOTEMPTY       __SL_ENOTEMPTY
#define ENOEXEC         __SL_ENOEXEC
#define EEXIST          __SL_EEXIST
#define EFBIG           __SL_EFBIG
#define ENAMETOOLONG    __SL_ENAMETOOLONG
#define ENOSYS          __SL_ENOSYS
#define EHOSTUNREACH    __SL_EHOSTUNREACH
#define EIDRM           __SL_EIDRM
#define EILSEQ          __SL_EILSEQ
#define ENOTTY          __SL_ENOTTY
#define EINTR           __SL_EINTR
#define EINVAL          __SL_EINVAL
#define ESPIPE          __SL_ESPIPE
#define EIO             __SL_EIO
#define EISDIR          __SL_EISDIR
#define EMSGSIZE        __SL_EMSGSIZE
#define ENETDOWN        __SL_ENETDOWN
#define ENETRESET       __SL_ENETRESET
#define ENETUNREACH     __SL_ENETUNREACH
#define ENOBUFS         __SL_ENOBUFS
#define ECHILD          __SL_ECHILD
#define ENOLINK         __SL_ENOLINK
#define ENOLCK          __SL_ENOLCK
#define ENODATA         __SL_ENODATA
#define ENOMSG          __SL_ENOMSG
#define ENOPROTOOPT     __SL_ENOPROTOOPT
#define ENOSPC          __SL_ENOSPC
#define ENOSR           __SL_ENOSR
#define ENXIO           __SL_ENXIO
#define ENODEV          __SL_ENODEV
#define ENOENT          __SL_ENOENT
#define ESRCH           __SL_ESRCH
#define ENOTDIR         __SL_ENOTDIR
#define ENOTSOCK        __SL_ENOTSOCK
#define ENOSTR          __SL_ENOSTR
#define ENOTCONN        __SL_ENOTCONN
#define ENOMEM          __SL_ENOMEM
#define ENOTSUP         __SL_ENOTSUP
#define ECANCELED       __SL_ECANCELED
#define EINPROGRESS     __SL_EINPROGRESS
#define EPERM           __SL_EPERM
#define EOPNOTSUPP      __SL_EOPNOTSUPP
#define EWOULDBLOCK     __SL_EWOULDBLOCK
#define EOWNERDEAD      __SL_EOWNERDEAD
#define EACCES          __SL_EACCES
#define EPROTO          __SL_EPROTO
#define EPROTONOSUPPORT __SL_EPROTONOSUPPORT
#define EROFS           __SL_EROFS
#define EDEADLK         __SL_EDEADLK
#define EAGAIN          __SL_EAGAIN
#define ERANGE          __SL_ERANGE
#define ENOTRECOVERABLE __SL_ENOTRECOVERABLE
#define ETIME           __SL_ETIME
#define ETXTBSY         __SL_TXTBSY
#define ETIMEDOUT       __SL_ETIMEDOUT
#define ENFILE          __SL_ENFILE
#define EMFILE          __SL_EMFILE
#define EMLINK          __SL_EMLINK
#define ELOOP           __SL_ELOOP
#define EOVERFLOW       __SL_EOVERFLOW
#define EPROTOTYPE      __SL_EPROTOTYPE
#define ELAST           __SL_ELAST
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// errno variable
//
extern errno_t errno;
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_ERRNO_H__ */

//-<EOF>
