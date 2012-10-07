/*==============================================================================
  Snow Leopard C++ Tools
  
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
// iostream.hpp
//------------------------------------------------------------------------------
// Standard iostream implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_IOSTREAM_HPP__
#define __SL_STDCPP_IMPL_IOSTREAM_HPP__

#include <sl/config/config.hpp>

#include <sl/stdcpp/ios.hpp>
#include <sl/stdcpp/istream.hpp>
#include <sl/stdcpp/ostream.hpp>
#include <sl/stdcpp/streambuf.hpp>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // Narrow character streams
  extern istream cin;
  extern ostream cout;
  extern ostream cerr;
  extern ostream clog;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Wide character streams
  extern wistream wcin;
  extern wostream wcout;
  extern wostream wcerr;
  extern wostream wclog;
  //----------------------------------------------------------------------------

} //std
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_IOSTREAM_HPP__ */

//-<EOF>
