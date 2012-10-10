/*==============================================================================
  Snow Leopard Compiler Project
  
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
// macros.h
//------------------------------------------------------------------------------
// Helper macros.
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_MACROS_H__
#define __SL_CONFIG_MACROS_H__

//------------------------------------------------------------------------------
// sl_str macro
//
// Macro to put double quotes around a macro + indirection required by the
// standard
#define sl_internal_str(s) # s
#define sl_str(s) sl_internal_str(s)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sl_concat_2 macro
//
// Concatenates 2 tokens + indirection required as defined by the standard.
#define sl_internal_concat_2(s1,s2) s1 ## s2
#define sl_concat_2(s1,s2) sl_internal_concat_2(s1,s2)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sl_concat_3 macro
//
// Concatenates 3 tokens + indirection required as defined by the standard.
#define sl_internal_concat_3(s1,s2,s3) s1 ## s2 ## s3
#define sl_concat_3(s1,s2,s3) sl_internal_concat_3(s1,s2,s3)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// sl_include_config macro
#ifdef __SL_NO_SL_STDLIB
# define sl_include_config(config_header) sl_str(config_header)
#else		    
# define sl_include_config(config_header) sl_str(config_header)   
#endif
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_MACROS_H__ */

//-<EOF>
