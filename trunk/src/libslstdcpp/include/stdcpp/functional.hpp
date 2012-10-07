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
// functional.hpp
//------------------------------------------------------------------------------
// Standard functional implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_FUNCTIONAL_HPP__
#define __SL_STDCPP_IMPL_FUNCTIONAL_HPP__

#include <sl/config/config.hpp>

//------------------------------------------------------------------------------
// Components in this header
#include <sl/stdcpp/hash.hpp>
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifndef __SL_COMPILER_USE_EXPORT__
# include <sl/stdcpp/implementation/hash.ipp>
#endif /* !__SL_COMPILER_USE_EXPORT__ */
////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_STDCPP_IMPL_FUNCTIONAL_HPP__ */

//-<EOF>
