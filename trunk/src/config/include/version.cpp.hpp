/*==============================================================================
  Snow Leopard Compiler Project
  
  Copyright (C) 2008, 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// version.cpp.hpp
//------------------------------------------------------------------------------
// Global version information.
//------------------------------------------------------------------------------

#ifndef __SL_CONFIG_VERSION_CPP_HPP__
#define __SL_CONFIG_VERSION_CPP_HPP__

//------------------------------------------------------------------------------
// Version numbers.
const unsigned short sl::config::MajorVersion = 0;
const unsigned short sl::config::MinorVersion = 0;
const unsigned short sl::config::Release = 1;
const char* sl::config::VersionLabel = "Initial Test Version";
const std::size_t sl::config::MaxVersionLabelSize = 512;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Prints program version information.
char* sl::config::get_version_string(char* buffer) {
  std::sprintf(
      buffer, "version %i.%i.%i build %i (%s)",
      MajorVersion, MinorVersion, Release, Build, VersionLabel
      );

  return buffer;
}
//------------------------------------------------------------------------------

#endif /* !__SL_CONFIG_VERSION_CPP_HPP__ */

//-<EOF>
