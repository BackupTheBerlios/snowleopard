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
// typeinfo.hpp
//------------------------------------------------------------------------------
// Standard type information implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_TYPEINFO_HPP__
#define __SL_STDCPP_IMPL_TYPEINFO_HPP__

#include <cstddef>
#include <exception>

//==============================================================================
namespace std {
 
  //----------------------------------------------------------------------------
  // type_info class
  class type_info {
   public:
     type_info(const type_info& rhs) = delete;
     virtual ~type_info();

     type_info& operator=(const type_info& rhs) = delete;

     bool operator==(const type_info& rhs) const noexcept;
     bool operator!=(const type_info& rhs) const noexcept;

     bool before(const type_info& rhs) const noexcept;

     size_t hash_code() const noexcept;
     const char* name() const noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // bad_cast class
  class bad_cast : public exception {
   public:
     bad_cast() noexcept;
     bad_cast(const bad_cast&) noexcept;

     bad_cast& operator=(const bad_cast&) noexcept;

     virtual const char* what() const noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // bad_typeid class
  class bad_typeid : public exception {
   public:
     bad_typeid() noexcept;
     bad_typeid(const bad_typeid&) noexcept;

     bad_typeid& operator=(const bad_typeid&) noexcept;

     virtual const char* what() const noexcept;
  };
  //----------------------------------------------------------------------------

} //std
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_TYPEINFO_HPP__ */

//-<EOF>

