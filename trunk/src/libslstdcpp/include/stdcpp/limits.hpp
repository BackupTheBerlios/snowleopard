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
// limits.hpp
//------------------------------------------------------------------------------
// Standard limits implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_LIMITS_HPP__
#define __SL_STDCPP_IMPL_LIMITS_HPP__

#include <sl/config/config.hpp>

//==============================================================================
namespace std {

//==============================================================================
// numeric_limits

  //----------------------------------------------------------------------------
  // float_round_style enum
  enum float_round_style {
    round_indeterminate       = -1,
    round_toward_zero         = 0,
    round_to_nearest          = 1, 
    round_toward_infinity     = 2,
    round_toward_neg_infinity = 3
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // float_denorm_style enum
  enum float_denorm_style {
    denorm_indeterminate = -1,
    denorm_absent        = 0,
    denorm_present       = 1
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // numeric_limits template
  template<typename T>
  class numeric_limits {

    static constexpr bool is_specialized = false;

    static constexpr T min() noexcept {
      return T();
    }

    static constexpr T max() noexcept {
      return T();
    }

    static constexpr T lowest() noexcept {
      return T();
    }

    static constexpr int digits = 0;
    static constexpr int digits10 = 0;
    static constexpr int max_digits10 = 0;
    static constexpr bool is_signed = false;
    static constexpr bool is_integer = false;
    static constexpr bool is_exact = false;
    static constexpr int radix = 0;

    static constexpr T epsilon() noexcept {
      return T();
    }

    static constexpr T round_error() noexcept {
      return T();
    }

    static constexpr int min_exponent = 0;
    static constexpr int min_exponent10 = 0;
    static constexpr int max_exponent = 0;
    static constexpr int max_exponent10 = 0;

    static constexpr bool has_infinity = false;
    static constexpr bool has_quiet_NaN = false;
    static constexpr bool has_signaling_NaN = false;
    static constexpr float_denorm_style has_denorm = denorm_absent;
    static constexpr bool has_denorm_loss = false;

    static constexpr T infinity() noexcept {
      return T();
    }

    static constexpr T quiet_NaN() noexcept {
      return T();
    }

    static constexpr T signaling_NaN() noexcept {
      return T();
    }
    
    static constexpr T denorm_min() noexcept {
      return T();
    }

    static constexpr bool is_iec559 = false;
    static constexpr bool is_bounded = false;
    static constexpr bool is_modulo = false;

    static constexpr bool traps = false;
    static constexpr bool tinyness_before = false;
    static constexpr float_round_style round_style = round_toward_zero;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // Partial specializations of numeric_limits
  template<class T>
  class numeric_limits<const T>;

  template<class T>
  class numeric_limits<volatile T>;

  template<class T>
  class numeric_limits<const volatile T>;
  //----------------------------------------------------------------------------

//==============================================================================

} /* std */
//==============================================================================

//------------------------------------------------------------------------------
// Include specializations for limits.
#include <sl/stdcpp/limits_specializations.hpp>
//------------------------------------------------------------------------------

#endif //__SL_STDCPP_IMPL_LIMITS_HPP__

//-<EOF>
