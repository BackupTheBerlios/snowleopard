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
// stdexcept.hpp
//------------------------------------------------------------------------------
// Standard exception classes
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_STDEXCEPT_HPP__
#define __SL_STDCPP_IMPL_STDEXCEPT_HPP__

#include <exception>
#include <string>

//==============================================================================
namespace std {

//==============================================================================
// Logic Errors

  //----------------------------------------------------------------------------
  // logic_error class
  class logic_error : public exception {
   public:
     explicit logic_error(const string& what_arg);
     explicit logic_error(const char* what_arg);
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // domain_error class
  class domain_error : public logic_error {
   public:
     explicit domain_error(const string& what_arg);
     explicit domain_error(const char* what_arg);
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // invalid_argument class
  class invalid_argument : public logic_error {
   public:
     explicit invalid_argument(const string& what_arg);
     explicit invalid_argument(const char* what_arg);
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // length_error class
  class length_error : public logic_error {
   public:
     explicit length_error(const string& what_arg);
     explicit length_error(const char* what_arg);
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // out_of_range class
  class out_of_range : public logic_error {
   public:
     explicit out_of_range(const string& what_arg);
     explicit out_of_range(const char* what_arg);
  };
  //----------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// Runtime Errors

  //----------------------------------------------------------------------------
  // runtime_error class
  class runtime_error : public exception {
   public:
     explicit runtime_error(const string& what_arg);
     explicit runtime_error(const char* what_arg);
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // range_error class
  class range_error : public runtime_error {
   public:
     explicit range_error(const string& what_arg);
     explicit range_error(const char* what_arg);
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // overflow_error class
  class overflow_error : public runtime_error {
   public:
     explicit overflow_error(const string& what_arg);
     explicit overflow_error(const char* what_arg);
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // underflow_error class
  class underflow_error : public runtime_error {
   public:
     explicit underflow_error(const string& what_arg);
     explicit underflow_error(const char* what_arg);
  };
  //----------------------------------------------------------------------------

//==============================================================================

} /* std */
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_STDEXCEPT_HPP__ */

//-<EOF>
