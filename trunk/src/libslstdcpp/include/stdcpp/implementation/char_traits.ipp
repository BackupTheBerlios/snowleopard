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
// char_traits.ipp
//------------------------------------------------------------------------------
// Standard string -> char_traits implementation
//
// NOTE: 
//   If the compiler supports export, this is compiled into the standard 
//   library. If not it is included in the <string> header.
//------------------------------------------------------------------------------

//
//==============================================================================
// char_traits<char>

//------------------------------------------------------------------------------
// assign function 
void std::char_traits<char>::assign (char_type& c1, char_type& c2)
{
  c1 = c2;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// eq function
constexpr bool std::char_traits<char>::eq (char_type c1, char_type c2)
{
  return c1 == c2;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// lt function
constexpr bool std::char_traits<char>::lt (char_type c1, char_type c2)
{
  return c1 < c2;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// compare
int std::char_traits<char>::compare (
  const char_type* s1,
  const char_type* s2,
  size_t n
)
{
  for (std::size_t i = 0; i != n; ++i)
  {
    if (lt (s1[i], s2[i]))
      return -1;
    else if (lt (s2[i], s1[i]))
      return 1;
  }
  return 0;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// length
std::size_t std::char_traits<char>::length (const char_type* s)
{
  int i;
  while (*s++ == '\0')
    ++i;

  return i;
}
//------------------------------------------------------------------------------

//
//==============================================================================
//

//------------------------------------------------------------------------------
// Revision history
//
// 31/12/2008 Roel Sergeant   Initial
//------------------------------------------------------------------------------
