/*==============================================================================
  Lynx Typesetting System
  
  Copyright (C) 2012 Roel Sergeant
  
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
// lsoelim_driver.c
//------------------------------------------------------------------------------
// Driver functions for the lsoelim.
//------------------------------------------------------------------------------

#include <stdbool.h>
#include <string.h>

#include "driver.h"
#include "settings.h"

//------------------------------------------------------------------------------
// drv_initialize function
//
// Initializes the driver.
//
bool drv_initialize ()
{
  return settings_initialize ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_cleanup function
//
// Cleans up after the elimination process has finished.
//
void drv_cleanup ()
{
  settings_cleanup ();
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// drv_start function
// 
// Start the process.
//
bool drv_start ()
{
  return true;
}
//------------------------------------------------------------------------------

//-<EOF>
