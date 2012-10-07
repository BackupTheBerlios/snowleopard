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
// exception.hpp
//------------------------------------------------------------------------------
// Standard exception implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_EXCEPTION_HPP__
#define __SL_STDCPP_IMPL_EXCEPTION_HPP__

#include <sl/config/config.hpp>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // exception class
  class exception {
   public:
     exception() noexcept;
     exception(const exception&) noexcept;
     virtual ~exception() noexcept;

     exception& operator=(const exception&) noexcept;

     virtual const char* what() const noexcept;

   private:
     const char* what_;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // bad_exception class
  class bad_exception : public exception {
   public:
     bad_exception() noexcept;
     bad_exception(const bad_exception&) noexcept;

     bad_exception& operator=(const bad_exception&) noexcept;

     virtual const char* what() const noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // exception_ptr type
  typedef exception* exception_ptr;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // nested_exception class
  class nested_exception {
   public:
     nested_exception() noexcept;
     nested_exception(const nested_exception&) noexcept;
     virtual ~nested_exception();

     nested_exception& operator=(const nested_exception&) noexcept;

     _Noreturn void rethrow_nested() const;
     exception_ptr nested_ptr() const noexcept;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Unexpected handler
  typedef void (*unexpected_handler)();

  unexpected_handler get_unexpected() noexcept;
  unexpected_handler set_unexpected(unexpected_handler f) noexcept;
  _Noreturn void unexpected();
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Terminate handler
  typedef void (*terminate_handler)();

  terminate_handler get_terminate() noexcept;
  terminate_handler set_terminate(terminate_handler f) noexcept;
  _Noreturn void terminate() noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // uncaught_exception function
  bool uncaught_exception() noexcept;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // current_exception function
  _Noreturn void rethrow_exception (exception_ptr);
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Rethrow functions
  _Noreturn void rethrow_exception(exception_ptr p);

  template<typename E> 
  exception_ptr make_exception_ptr(E e) noexcept;

  template<typename T> 
  _Noreturn void throw_with_nested (T&& t);

  template<typename E> 
  void rethrow_if_nested (const E& e);
  //----------------------------------------------------------------------------
  	
} /* std */
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifndef __SL_COMPILER_USE_EXPORT
# include <sl/stdcpp/implementation/exception.ipp>
#endif /* !__SL_COMPILER_USE_EXPORT */
////////////////////////////////////////////////////////////////////////////////

#endif /* !__SL_STDCPP_IMPL_EXCEPTION_HPP__ */

//-<EOF>
