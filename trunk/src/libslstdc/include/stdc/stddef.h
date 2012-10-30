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
// stddef.h
//------------------------------------------------------------------------------
// Standard definition implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDC_IMPL_STDDEF_H__
#define __SL_STDC_IMPL_STDDEF_H__

#include "stdc/config_stdc.h"

#include "stdc/private/shared_macros.h"
#include "stdc/private/shared_types.h"

//------------------------------------------------------------------------------
// NULL macro
// 
// NULL is defined in private/shared_macros.h"
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// size types
//
// size_t is defined in private/shared_types.h
//
typedef __SL_ConfigNamespace  sl_diff_t diff_t;
typedef __SL_ConfigNamespace  sl_diff_t ptrdiff_t;
typedef __SL_ConfigNamespace  sl_size_t max_align_t;
typedef __SL_ConfigNamespace  sl_size_t rsize_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// wchar_t/wint_t/char16_t/char32_t type
#ifndef __cplusplus
  typedef __SL_ConfigNamespace  sl_wchar_t wchar_t;
  typedef __SL_ConfigNamespace  sl_char16_t char16_t;
  typedef __SL_ConfigNamespace  sl_char32_t char32_t;
#endif /* !__cplusplus */
typedef __SL_ConfigNamespace  sl_wint_t wint_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// mbstate_t struct
struct mbstate_t {
  int count;
  union {
    wchar_t wch;
    char wchb[4];
  } value;
};

typedef struct mbstate_t mbstate_t;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// offsetof macro
#define offsetof(st, m)                                                 \
  ((size_t) ((char *) &((st *) (0))->m - (char *) &((st *) (0))))
//------------------------------------------------------------------------------

#endif /* !__SL_STDC_IMPL_STDDEF_H__ */

//-<EOF>
