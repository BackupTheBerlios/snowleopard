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
// new.hpp
//------------------------------------------------------------------------------
// Standard new implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_NEW_HPP__
#define __SL_STDCPP_IMPL_NEW_HPP__

#include <sl/config/config.hpp>

#include <cstddef>
#include <exception>

//==============================================================================
namespace std {
 
  //----------------------------------------------------------------------------
  // bad_alloc class
  class bad_alloc : public exception {
  public:
    bad_alloc() noexcept;
    bad_alloc(const bad_alloc& ba) noexcept;

    bad_alloc& operator=(const bad_alloc& ba) noexcept;

    virtual const char* what() const noexcept;
  };
  //----------------------------------------------------------------------------
  
  //----------------------------------------------------------------------------
  // bad_array_new_length class
  class bad_array_new_length : public bad_alloc {
  public:
    bad_array_new_length() noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // nothrow_t struct / nothrow constant
  struct nothrow_t {};
  extern const nothrow_t nothrow;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // new_handler type
  typedef void (*new_handler)();
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // new_handler functions
  new_handler get_new_handler() noexcept;
  new_handler set_new_handler(new_handler new_p) noexcept;
  //----------------------------------------------------------------------------

} //std
//==============================================================================

//------------------------------------------------------------------------------
// Single object forms
void* operator new(std::size_t size);
void* operator new(std::size_t size, const std::nothrow_t&) noexcept;
void operator delete(void* ptr) noexcept;
void operator delete(void* ptr, const std::nothrow_t&) noexcept;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Array forms
void* operator new[](std::size_t size);
void* operator new[](std::size_t size, const std::nothrow_t&) noexcept;
void operator delete[](void* ptr) noexcept;
void operator delete[](void* ptr, const std::nothrow_t&) noexcept;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Placement forms
void* operator new(std::size_t size, void* ptr) noexcept;
void* operator new[](std::size_t size, void* ptr) noexcept;
void operator delete(void* ptr, void*) noexcept;
void operator delete[](void* ptr, void*) noexcept;
//------------------------------------------------------------------------------

#endif /* !__SL_STDCPP_IMPL_NEW_HPP__ */

//-<EOF>

