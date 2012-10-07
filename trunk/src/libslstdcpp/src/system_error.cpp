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
// system_error.cpp
//------------------------------------------------------------------------------
// Standard system error implementation
//------------------------------------------------------------------------------

#include <string>
#include <system_error>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // __generic_category class
  class __generic_category : public error_category {
   public:
    __generic_category();
    
    virtual const char* name() const noexcept;
    virtual string message(int ev) const;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // __system_category class
  class __system_category : public error_category {
   public:
    __system_category();
    
    virtual const char* name() const noexcept;
    virtual string message(int ev) const;
  };
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

//==============================================================================
// __generic_category class
//------------------------------------------------------------------------------
// name function
const char* std::__generic_category::name() const noexcept {
  return "generic";
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// message function
std::string std::__generic_category::message(int ev) const {
  if(ev > ELAST)
    return std::string("unspecified generic_category error");
  return std::error_category::message(ev);
}
//------------------------------------------------------------------------------
//==============================================================================

//==============================================================================
// __system_category class
//------------------------------------------------------------------------------
// name function
const char* std::__system_category::name() const noexcept {
  return "system";
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// message function
std::string std::__system_category::message(int ev) const {
  if(ev > ELAST)
    return std::string("unspecified system_category error");
  return std::error_category::message(ev);
}
//------------------------------------------------------------------------------
//==============================================================================

//------------------------------------------------------------------------------
// generic_category function
const std::error_category& std::generic_category() noexcept {
  static std::__generic_category c;
  return c;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// system_category function
const std::error_category& std::system_category() noexcept {
  static std::__system_category c;
  return c;
}
//------------------------------------------------------------------------------

//-<EOF>
