/*==============================================================================
  Lynx Typesetting System
  
  Copyright (C) 2009, 2010, 2011, 2012 Roel Sergeant
  
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
// driver.hpp
//------------------------------------------------------------------------------
// Driver class for the Lynx typesetting system.
//------------------------------------------------------------------------------

#ifndef __LYNX_DRIVER_HPP__
#define __LYNX_DRIVER_HPP__

//==============================================================================
namespace lynx {

  //-----------------------------------------------------------------------------
  // driver class
  class driver {
  public:
    driver(int argc, char** argv);

    bool start();

  private:
    bool parse_command_line(int argc, char** argv);
  };
  //----------------------------------------------------------------------------

} /* lynx */
//==============================================================================

#endif /* !__LYNX_DRIVER_HPP__ */

//-<EOF>
