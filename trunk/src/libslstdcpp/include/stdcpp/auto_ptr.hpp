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
// auto_ptr.hpp
//------------------------------------------------------------------------------
// Standard auto_ptr implementation
//
// auto_ptr is deprecated in C++11
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_AUTO_PTR_HPP__
#define __SL_STDCPP_IMPL_AUTO_PTR_HPP__

//------------------------------------------------------------------------------
// This header should not be included by itself.
#ifndef __SL_STDCPP_IMPL_MEMORY_HPP__

# error "The header auto_ptr.hpp should not be included directly"

#else /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */

#include <sl/config/config.hpp>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // auto_ptr_ref struct
  template<typename Y>
  struct auto_ptr_ref 
  {
    Y* ptr;

    auto_ptr_ref (Y*);
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // auto_ptr class
  template<typename T>
  class auto_ptr 
  {
   private:
    T* ptr;

   public:
    typedef T element_type;

    explicit auto_ptr(T* rhs = 0) noexcept;
    auto_ptr(auto_ptr&) noexcept;
    template<typename U> auto_ptr(auto_ptr<U>&) noexcept;
    auto_ptr(auto_ptr_ref<T>) noexcept;
    ~auto_ptr() noexcept;
    
    auto_ptr& operator=(auto_ptr&) noexcept;
    template<typename U> auto_ptr& operator=(auto_ptr<U>&) noexcept;
    auto_ptr& operator=(auto_ptr_ref<T>) noexcept;
    
    template<typename U> operator auto_ptr_ref<U>() noexcept;
    template<typename U> operator auto_ptr<U>() noexcept;
    
    T* get() const noexcept;
    T& operator*() const noexcept;
    T* operator->() const noexcept;
    
    T* release() noexcept;
    
    void reset(T* rhs = 0) noexcept;

  };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_MEMORY_HPP__ */
//------------------------------------------------------------------------------

#endif /* !__SL_STDCPP_IMPL_AUTO_PTR_HPP__ */

//-<EOF>
