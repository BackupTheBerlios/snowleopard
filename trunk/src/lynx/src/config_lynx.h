/*==============================================================================
  Mountain Lion Project

  Copyright (C) 2010, 2011, 2012 Roel Sergeant
  All rights reserved.
 
  Redistribution and use in source and binary forms, with or without 
  modification, are permitted provided that the following conditions are met:
 
   o Redistributions of source code must retain the above copyright notice, 
     this list of conditions and the following disclaimer.
   o Redistributions in binary form must reproduce the above copyright notice, 
     this list of conditions and the following disclaimer in the documentation 
     and/or other materials provided with the distribution.
            
  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
  POSSIBILITY OF SUCH DAMAGE.
  ============================================================================*/

//------------------------------------------------------------------------------
// config_lynx.h
//------------------------------------------------------------------------------
// Configuration information for the Lynx typesetting system.
//------------------------------------------------------------------------------

#ifndef __LYNX_CONFIG_LYNX_H__
#define __LYNX_CONFIG_LYNX_H__

#ifdef __LYNX_NO_SL_STDLIB
#define __SL_NO_SL_STDLIB
#endif /* __LYNX_NO_SL_STDLIB */

#ifdef __SL_INSTALLED
# include "sl/config/macros.h"
#else /* __SL_INSTALLED */
# include "macros.h"
#endif /* __SL_INSTALLED */

#include sl_include_config(config.h)

#endif /* !__LYNX_CONFIG_LYNX_H__ */

//-<EOF>

