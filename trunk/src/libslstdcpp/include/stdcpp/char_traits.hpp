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
// char_traits.hpp
//------------------------------------------------------------------------------
// char_traits template class
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_CHAR_TRAITS_HPP__
#define __SL_STDCPP_IMPL_CHAR_TRAITS_HPP__

//------------------------------------------------------------------------------
// This header should not be included by itself.
#ifndef __SL_STDCPP_IMPL_STRING_HPP__

# error "The header basic_string.hpp should not be included directly"

#else /* !__SL_STDCPP_IMPL_STRING_HPP__ */

#include <sl/config/config.hpp>

#include <cstddef>
#include <cwchar>
#include <iosfwd>
#include <stream_types>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // char_traits template class
  template<typename CharT> struct char_traits;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // char_traits<char> specialization
  template<> struct char_traits<char> {
    typedef char char_type;
    typedef int int_type;
    typedef streamoff off_type;
    typedef streampos pos_type;
    typedef __SL_StateT state_type;

    static void assign (char_type& c1, char_type& c2);
    static constexpr bool eq (char_type c1, char_type c2);
    static constexpr bool lt (char_type c1, char_type c2);

    static int compare (const char_type* s1, const char_type* s2, size_t n);
    static size_t length (const char_type* s);
    static const char_type* find (
				  const char_type* s,
				  size_t n,
				  const char_type& a
                                  );
    static char_type* move (char_type* s1, const char_type* s2, size_t n);
    static char_type* copy (char_type* s1, const char_type* s2, size_t n);
    static char_type* assign (char_type* s1, size_t n, char_type a);
    
    static constexpr int_type not_eof (int_type c);
    static constexpr char_type to_char_type (int_type c);
    static constexpr int_type to_int_type (char_type c);
    static constexpr bool eq_int_type (int_type c1, int_type c2);
    static constexpr int_type eof ();    
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // char_traits<char16_t> specialization

  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // char_traits<char32_t> specialization

  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // char_traits<wchar_t> specialization

  //----------------------------------------------------------------------------
   
} //std
//==============================================================================

#endif /* !__SL_STDCPP_IMPL_STRING_HPP__ */
//------------------------------------------------------------------------------

#endif //__SL_STDCPP_IMPL_CHAR_TRAITS_HPP__

//-<EOF>
