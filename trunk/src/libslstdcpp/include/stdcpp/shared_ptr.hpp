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
// shared_ptr.hpp
//------------------------------------------------------------------------------
// Standard shared pointer implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_SHARED_PTR_HPP__
#define __SL_STDCPP_IMPL_SHARED_PTR_HPP__

//------------------------------------------------------------------------------
// This header should not be included by itself.
#ifndef __SL_STDCPP_IMPL_MEMORY_HPP__

# error "The header shared_ptr.hpp should not be included directly"

#else /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */

#include <sl/config/config.hpp>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // shared_ptr class template
  template<class T> class shared_ptr {
  };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */
//------------------------------------------------------------------------------

#endif /* !__SL_STDCPP_IMPL_SHARED_PTR_HPP__ */

//-<EOF>
