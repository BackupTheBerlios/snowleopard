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
// string.hpp
//------------------------------------------------------------------------------
// Standard string implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_STRING_HPP__
#define __SL_STDCPP_IMPL_STRING_HPP__

#include <sl/config/config.hpp>

//------------------------------------------------------------------------------
// Components of this header
#include <sl/stdcpp/char_traits.hpp>
#include <sl/stdcpp/basic_string.hpp>
#include <sl/stdcpp/string_ops.hpp>
#include <sl/stdcpp/string_swap.hpp>
#include <sl/stdcpp/string_insert_extract.hpp>
#include <sl/stdcpp/string_numeric_conv.hpp>
//------------------------------------------------------------------------------

//==============================================================================
namespace std {

  //----------------------------------------------------------------------------
  // string types
  typedef basic_string<char> string;
  typedef basic_string<char16_t> u16string;
  typedef basic_string<char32_t> u32string;
  typedef basic_string<wchar_t> wstring;
  //----------------------------------------------------------------------------

} /* std */
//==============================================================================

////////////////////////////////////////////////////////////////////////////////
// If compiler uses export, don't include source for templates
#ifndef __SL_COMPILER_USE_EXPORT__
# include <sl/stdcpp/implementation/char_traits.ipp>
# include <sl/stdcpp/implementation/basic_string.ipp>
# include <sl/stdcpp/implementation/string_ops_plus.ipp>
# include <sl/stdcpp/implementation/string_rel_ops.ipp>
# include <sl/stdcpp/implementation/string_swap.ipp>
# include <sl/stdcpp/implementation/string_insert_extract.ipp>
# include <sl/stdcpp/implementation/string_numeric_conv.ipp>
#endif /* !__SL_COMPILER_USE_EXPORT__ */
////////////////////////////////////////////////////////////////////////////////

#endif /* __SL_STDCPP_IMPL_STRING_HPP__ */

//-<EOF>
