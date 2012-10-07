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
// memory.hpp
//------------------------------------------------------------------------------
// Standard memory implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_MEMORY_HPP__
#define __SL_STDCPP_IMPL_MEMORY_HPP__

#include <sl/config/config.hpp>

//------------------------------------------------------------------------------
// Components of this header
#include <sl/stdcpp/pointer_traits.hpp>
#include <sl/stdcpp/allocator.hpp>
#include <sl/stdcpp/specialized_algorithms.hpp>
#include <sl/stdcpp/shared_ptr.hpp>
#if __cplusplus == 201103L
# ifdef __SL_NO_DEPRECATED_FEATURES__
#  warning "auto_ptr is a deprecated feature"
#  include <sl/stdcpp/auto_ptr.hpp>
# endif /* __SL_NO_DEPRECATED_FEATURES__ */
#endif /* __cplusplus == 201103L */
//------------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifndef __SL_COMPILER_USE_EXPORT__
#if __cplusplus == 201103L
# ifdef __SL_NO_DEPRECATED_FEATURES__
#  include <sl/stdcpp/detail/auto_ptr.ipp>
# endif /* __SL_NO_DEPRECATED_FEATURES__ */
#endif /* __cplusplus == 201103L */
#endif /* !__SL_COMPILER_USE_EXPORT__ */
////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */

//-<EOF>
