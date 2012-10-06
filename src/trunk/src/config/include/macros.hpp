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
// macros.hpp
//------------------------------------------------------------------------------
// Helper macros.
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_MACROS_HPP__
#define __SL_CONFIG_MACROS_HPP__

#ifdef __SL_NO_SL_STDLIB
# include <config/macros.h>
#else /* __SL_NO_SL_STDLIB */
# include <sl/config/macros.h>
#endif /* __SL_NO_SL_STDLIB */

//------------------------------------------------------------------------------
// sl_use_type_if_exists
//
// Macro checks if a type exists and if not use the second parameter as type
#define sl_use_type_or_alt(template_param,type,alt_type)	    \
  template<typename T>						    \
    static typename T::type __SL_##type##_helper(T);		    \
  static alt_type __SL_##type##_helper(...);			    \
  typedef decltype(__SL_##type##_helper((template_param*)0)) sl_##type;
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_MACROS_HPP__ */

//-<EOF>
