 /*==============================================================================
  Snow Leopard C++ Tools
  
  Copyright (C) 2008 Roel Sergeant
  
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
// rel_ops.ipp
//------------------------------------------------------------------------------
// Standard utility -> rel_ops implementation
//
// NOTE: 
//   If the compiler supports export, this is compiled into the standard 
//   library. If not it is included in the <utility> header.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// operator !=
template<typename T>
bool std::rel_ops::operator!= (const T& lhs, const T& rhs)
{
  return ! ( lhs == rhs );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// operator >
template<typename T>
bool std::rel_ops::operator> (const T& lhs, const T& rhs)
{
  return lhs < rhs;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// operator <=
template<typename T>
bool std::rel_ops::operator<= (const T& lhs, const T& rhs)
{
  return ! ( rhs < lhs );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// operator >=
template<typename T>
bool std::rel_ops::operator>= (const T& lhs, const T& rhs)
{
  return ! ( lhs < rhs );
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Revision history
//
// 13/11/2008 Roel Sergeant   Initial
// 08/12/2008 Roel Sergeant   Removed concepts for now
//------------------------------------------------------------------------------
