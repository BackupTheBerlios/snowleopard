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
// iosfwd.hpp
//------------------------------------------------------------------------------
// Standard iosfwd implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_IOSFWD_HPP__
#define __SL_STDCPP_IMPL_IOSFWD_HPP__

#include <sl/config/config.hpp>

#include <cwchar>
#include <string>

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // char_traits classes
  template<typename CharT> struct char_traits;

  template<> struct char_traits<char>;
  template<> struct char_traits<char16_t>;
  template<> struct char_traits<char32_t>;
  template<> struct char_traits<wchar_t>;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // allocator class
  template<typename T> class allocator;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Basic stream classes
  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_ios;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_streambuf;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_istream;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_ostream;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_iostream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // String stream classes
  template<
    typename CharT,
    typename Traits = char_traits<CharT>,
    typename Allocator = allocator<CharT>
    >
  class basic_stringbuf;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>,
    typename Allocator = allocator<CharT>
    >
  class basic_istringstream;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>,
    typename Allocator = allocator<CharT>
    >
  class basic_ostringstream;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>,
    typename Allocator = allocator<CharT>
    >
  class basic_stringstream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // File stream classes
  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_filebuf;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_ifstream;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_ofstream;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class basic_fstream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Stream iterators
  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class istreambuf_iterator;

  template<
    typename CharT,
    typename Traits = char_traits<CharT>
    >
  class ostreambuf_iterator;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // ios typedefs
  typedef basic_ios<char> ios;
  typedef basic_ios<wchar_t> wios;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Console stream typedefs (narrow)
  typedef basic_streambuf<char> streambuf;
  typedef basic_istream<char> istream;
  typedef basic_ostream<char> ostream;
  typedef basic_iostream<char> iostream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // String stream typedefs (narrow)
  typedef basic_stringbuf<char> stringbuf;
  typedef basic_istringstream<char> istringstream;
  typedef basic_ostringstream<char> ostringstream;
  typedef basic_stringstream<char> stringstream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // File stream typedefs (narrow)
  typedef basic_filebuf<char> filebuf;
  typedef basic_ifstream<char> ifstream;
  typedef basic_ofstream<char> ofstream;
  typedef basic_fstream<char> fstream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Console stream typedefs (wide)
  typedef basic_streambuf<wchar_t> wstreambuf;
  typedef basic_istream<wchar_t> wistream;
  typedef basic_ostream<wchar_t> wostream;
  typedef basic_iostream<wchar_t> wiostream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // String stream typedefs (wide)
  typedef basic_stringbuf<wchar_t> wstringbuf;
  typedef basic_istringstream<wchar_t> wistringstream;
  typedef basic_ostringstream<wchar_t> wostringstream;
  typedef basic_stringstream<wchar_t> wstringstream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // File stream typedefs (wide)
  typedef basic_filebuf<wchar_t> wfilebuf;
  typedef basic_ifstream<wchar_t> wifstream;
  typedef basic_ofstream<wchar_t> wofstream;
  typedef basic_fstream<wchar_t> wfstream;
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Position classes
  template<typename StateT> class fpos;

  typedef fpos<__SL_StateT> streampos;
  typedef fpos<__SL_StateT> wstreampos;
  //----------------------------------------------------------------------------

} //std
//==============================================================================

#endif /* !__SL_STDCPP__IMPL_IOSFWD_HPP__ */

//-<EOF>
