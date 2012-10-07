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
// limits_specializations.hpp
//------------------------------------------------------------------------------
// Standard limits specializations implementation
//------------------------------------------------------------------------------

#ifndef __SL_STDCPP_IMPL_LIMITS_SPECIALIZATIONS_HPP__
#define __SL_STDCPP_IMPL_LIMITS_SPECIALIZATIONS_HPP__

//------------------------------------------------------------------------------
// This header should not be included by itself.
#ifndef __SL_STDCPP_IMPL_LIMITS_HPP__

# error "The header limits_specializations.hpp should not be included directly"

#else /* __SL_STDCPP_IMPL_LIMITS_HPP__ */

//==============================================================================
namespace std {

//==============================================================================
// short limits

  //----------------------------------------------------------------------------
  // numeric_limits<short> specialization
  template<>
  class numeric_limits<short> {
    static const bool is_specialized = true;

    inline static short min() noexcept {
      return __SL_SHRT_MIN;
    }

    inline static short max() noexcept {
      return __SL_SHRT_MAX;
    }

    inline static short lowest() noexcept {
      return __SL_SHRT_MIN;
    }
    
    static const int digits = __SL_SHRT_NON_SIGN_BITS;
    static const int digits10 = __SL_SHRT_DIGITS10;
    static const int max_digits10 = __SL_SHRT_MAX_DIGITS10;
    static const bool is_signed = true;
    static const bool is_integer = true;
    static const bool is_excect = true;
    static const int radix = 2;

    static const bool is_bounded = true;
    static const bool is_modulo = true;

    static const bool traps = true;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // numeric_limits<unsigned short> specialization
  template<>
  class numeric_limits<unsigned short> {
    static const bool is_specialized = true;

    inline static unsigned short min() noexcept {
      return 0;
    }

    inline static unsigned short max() noexcept {
      return __SL_USHRT_MAX;
    }

    inline static unsigned short lowest() noexcept {
      return 0;
    }
    
    static const int digits = __SL_USHRT_NON_SIGN_BITS;
    static const int digits10 = __SL_USHRT_DIGITS10;
    static const int max_digits10 = __SL_USHRT_MAX_DIGITS10;
    static const bool is_signed = true;
    static const bool is_integer = true;
    static const bool is_excect = true;
    static const int radix = 2;

    static const bool is_bounded = true;
    static const bool is_modulo = true;

    static const bool traps = true;
  };
  //----------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// int limits

  //----------------------------------------------------------------------------
  // numeric_limits<int> specialization
  template<>
  class numeric_limits<int> {
    static const bool is_specialized = true;

    inline static int min() noexcept {
      return __SL_INT_MIN;
    }

    inline static int max() noexcept {
      return __SL_INT_MAX;
    }

    inline static int lowest() noexcept {
      return __SL_INT_MIN;
    }
    
    static const int digits = __SL_INT_NON_SIGN_BITS;
    static const int digits10 = __SL_INT_DIGITS10;
    static const int max_digits10 = __SL_INT_MAX_DIGITS10;
    static const bool is_signed = true;
    static const bool is_integer = true;
    static const bool is_excect = true;
    static const int radix = 2;

    static const bool is_bounded = true;
    static const bool is_modulo = true;

    static const bool traps = true;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // numeric_limits<unsigned int> specialization
  template<>
  class numeric_limits<unsigned int> {
    static const bool is_specialized = true;

    inline static unsigned int min() noexcept {
      return 0;
    }

    inline static unsigned int max() noexcept {
      return __SL_UINT_MAX;
    }

    inline static unsigned int lowest() noexcept {
      return 0;
    }
    
    static const int digits = __SL_UINT_NON_SIGN_BITS;
    static const int digits10 = __SL_UINT_DIGITS10;
    static const int max_digits10 = __SL_UINT_MAX_DIGITS10;
    static const bool is_signed = true;
    static const bool is_integer = true;
    static const bool is_excect = true;
    static const int radix = 2;

    static const bool is_bounded = true;
    static const bool is_modulo = true;

    static const bool traps = true;
  };
  //----------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// long limits

  //----------------------------------------------------------------------------
  // numeric_limits<long> specialization
  template<>
  class numeric_limits<long> {
    static const bool is_specialized = true;

    inline static long min() noexcept {
      return __SL_LONG_MIN;
    }

    inline static long max() noexcept {
      return __SL_LONG_MAX;
    }

    inline static long lowest() noexcept {
      return __SL_LONG_MIN;
    }
    
    static const int digits = __SL_LONG_NON_SIGN_BITS;
    static const int digits10 = __SL_LONG_DIGITS10;
    static const int max_digits10 = __SL_LONG_MAX_DIGITS10;
    static const bool is_signed = true;
    static const bool is_integer = true;
    static const bool is_excect = true;
    static const int radix = 2;

    static const bool is_bounded = true;
    static const bool is_modulo = true;

    static const bool traps = true;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // numeric_limits<unsigned long> specialization
  template<>
  class numeric_limits<unsigned long> {
    static const bool is_specialized = true;

    inline static unsigned long min() noexcept {
      return 0;
    }

    inline static unsigned long max() noexcept {
      return __SL_ULONG_MAX;
    }

    inline static unsigned long lowest() noexcept {
      return 0;
    }
    
    static const int digits = __SL_ULONG_NON_SIGN_BITS;
    static const int digits10 = __SL_ULONG_DIGITS10;
    static const int max_digits10 = __SL_ULONG_MAX_DIGITS10;
    static const bool is_signed = true;
    static const bool is_integer = true;
    static const bool is_excect = true;
    static const int radix = 2;

    static const bool is_bounded = true;
    static const bool is_modulo = true;

    static const bool traps = true;
  };
  //----------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// long long limits

  //----------------------------------------------------------------------------
  // numeric_limits<long long> specialization
  template<>
  class numeric_limits<long long> {
    static const bool is_specialized = true;

    inline static long long min() noexcept {
      return __SL_LLONG_MIN;
    }

    inline static long long max() noexcept {
      return __SL_LLONG_MAX;
    }

    inline static long long lowest() noexcept {
      return __SL_LLONG_MIN;
    }
    
    static const int digits = __SL_LLONG_NON_SIGN_BITS;
    static const int digits10 = __SL_LLONG_DIGITS10;
    static const int max_digits10 = __SL_LLONG_MAX_DIGITS10;
    static const bool is_signed = true;
    static const bool is_integer = true;
    static const bool is_excect = true;
    static const int radix = 2;

    static const bool is_bounded = true;
    static const bool is_modulo = true;

    static const bool traps = true;
  };
  //----------------------------------------------------------------------------

  //----------------------------------------------------------------------------
  // numeric_limits<unsigned long long> specialization
  template<>
  class numeric_limits<unsigned long long> {
    static const bool is_specialized = true;

    inline static unsigned long long min() noexcept {
      return 0;
    }

    inline static unsigned long long max() noexcept {
      return __SL_ULLONG_MAX;
    }

    inline static unsigned long long lowest() noexcept {
      return 0;
    }
    
    static const int digits = __SL_ULLONG_NON_SIGN_BITS;
    static const int digits10 = __SL_ULLONG_DIGITS10;
    static const int max_digits10 = __SL_ULLONG_MAX_DIGITS10;
    static const bool is_signed = true;
    static const bool is_integer = true;
    static const bool is_excect = true;
    static const int radix = 2;

    static const bool is_bounded = true;
    static const bool is_modulo = true;

    static const bool traps = true;
  };
  //----------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// float limits

  //----------------------------------------------------------------------------
  // numeric_limits<float> specialization
  template<>
  class numeric_limits<float> {
    static const bool is_specialized = true;

    inline static float min() noexcept {
      return __SL_FLOAT_MIN;
    }

    inline static float max() noexcept {
      return __SL_FLOAT_MAX;
    }

    inline static float lowest() noexcept {
      return __SL_FLOAT_LOWEST;
    }

    static const int digits = __SL_FLOAT_MANT_DIG;
    static const int digits10 = __SL_FLOAT_DECIMAL_DIG;
    static const int max_digits10 = __SL_FLOAT_MAX_DECIMAL_DIG;
    
    static const bool is_signed = true;
    static const bool is_integer = false;
    static const bool is_exact = false;
    
    static const int radix = __SL_FLOAT_G_RADIX;

    inline static float epsilon() noexcept {
      return __SL_FLOAT_EPSILON;
    }

    inline static float round_error() noexcept {
      return __SL_FLOAT_ROUND_ERROR;
    }

    static const int min_exponent = __SL_FLOAT_MIN_EXP;
    static const int max_exponent = __SL_FLOAT_MAX_EXP;
    static const int min_exponent10 = __SL_FLOAT_MIN_10_EXP;
    static const int max_exponent10 = __SL_FLOAT_MAX_10_EXP;

    static const bool has_infinity = true;
    static const bool has_quiet_NaN = true;
    static const bool has_signaling_NaN = true;
    static const float_denorm_style has_denorm = denorm_absent;
    static const bool has_denorm_loss = false;

    inline static float infinity() noexcept {
      return __SL_FLOAT_INFINITYF;
    }

    inline static float quiet_NaN() noexcept {
      return __SL_FLOAT_NANF;
    }

    inline static float signaling_NaN() noexcept {
      return __SL_FLOAT_NANF;
    }

    inline static float denorm_min() noexcept {
      return min();
    }

    static const bool is_iec559 = true;
    static const bool is_bounded = true;
    static const bool is_modulo = false;
    static const bool traps = true;
    static const bool tinyness_before = true;

    static const float_round_style round_style = round_to_nearest;
  };
  //----------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// double limits

  //----------------------------------------------------------------------------
  // numeric_limits<double> specialization
  template<>
  class numeric_limits<double> {
    static const bool is_specialized = true;

    inline static double min() noexcept {
      return __SL_DOUBLE_MIN;
    }

    inline static double max() noexcept {
      return __SL_DOUBLE_MAX;
    }

    inline static double lowest() noexcept {
      return __SL_DOUBLE_LOWEST;
    }

    static const int digits = __SL_DOUBLE_MANT_DIG;
    static const int digits10 = __SL_DOUBLE_DECIMAL_DIG;
    static const int max_digits10 = __SL_DOUBLE_MAX_DECIMAL_DIG;
    
    static const bool is_signed = true;
    static const bool is_integer = false;
    static const bool is_exact = false;
    
    static const int radix = __SL_FLOAT_G_RADIX;

    inline static double epsilon() noexcept {
      return __SL_DOUBLE_EPSILON;
    }

    inline static double round_error() noexcept {
      return __SL_DOUBLE_ROUND_ERROR;
    }

    static const int min_exponent = __SL_DOUBLE_MIN_EXP;
    static const int max_exponent = __SL_DOUBLE_MAX_EXP;
    static const int min_exponent10 = __SL_DOUBLE_MIN_10_EXP;
    static const int max_exponent10 = __SL_DOUBLE_MAX_10_EXP;

    static const bool has_infinity = true;
    static const bool has_quiet_NaN = true;
    static const bool has_signaling_NaN = true;
    static const float_denorm_style has_denorm = denorm_absent;
    static const bool has_denorm_loss = false;

    inline static double infinity() noexcept {
      return __SL_FLOAT_INFINITY;
    }

    inline static double quiet_NaN() noexcept {
      return __SL_FLOAT_NAN;
    }

    inline static double signaling_NaN() noexcept {
      return __SL_FLOAT_NAN;
    }

    inline static double denorm_min() noexcept {
      return min();
    }

    static const bool is_iec559 = true;
    static const bool is_bounded = true;
    static const bool is_modulo = false;
    static const bool traps = true;
    static const bool tinyness_before = true;

    static const float_round_style round_style = round_to_nearest;
  };
  //----------------------------------------------------------------------------

//==============================================================================

//==============================================================================
// long double limits

  //----------------------------------------------------------------------------
  // numeric_limits<long double> specialization
  template<>
  class numeric_limits<long double> {
    static const bool is_specialized = true;

    inline static long double min() noexcept {
      return __SL_LDOUBLE_MIN;
    }

    inline static long double max() noexcept {
      return __SL_LDOUBLE_MAX;
    }

    inline static long double lowest() noexcept {
      return __SL_LDOUBLE_LOWEST;
    }

    static const int digits = __SL_LDOUBLE_MANT_DIG;
    static const int digits10 = __SL_LDOUBLE_DECIMAL_DIG;
    static const int max_digits10 = __SL_LDOUBLE_MAX_DECIMAL_DIG;
    
    static const bool is_signed = true;
    static const bool is_integer = false;
    static const bool is_exact = false;
    
    static const int radix = __SL_FLOAT_G_RADIX;

    inline static long double epsilon() noexcept {
      return __SL_LDOUBLE_EPSILON;
    }

    inline static long double round_error() noexcept {
      return __SL_LDOUBLE_ROUND_ERROR;
    }

    static const int min_exponent = __SL_LDOUBLE_MIN_EXP;
    static const int max_exponent = __SL_LDOUBLE_MAX_EXP;
    static const int min_exponent10 = __SL_LDOUBLE_MIN_10_EXP;
    static const int max_exponent10 = __SL_LDOUBLE_MAX_10_EXP;

    static const bool has_infinity = true;
    static const bool has_quiet_NaN = true;
    static const bool has_signaling_NaN = true;
    static const float_denorm_style has_denorm = denorm_absent;
    static const bool has_denorm_loss = false;

    inline static long double infinity() noexcept {
      return __SL_FLOAT_INFINITYL;
    }

    inline static long double quiet_NaN() noexcept {
      return __SL_FLOAT_NANL;
    }

    inline static long double signaling_NaN() noexcept {
      return __SL_FLOAT_NANL;
    }

    inline static long double denorm_min() noexcept {
      return min();
    }

    static const bool is_iec559 = true;
    static const bool is_bounded = true;
    static const bool is_modulo = false;
    static const bool traps = true;
    static const bool tinyness_before = true;

    static const float_round_style round_style = round_to_nearest;
  };
  //----------------------------------------------------------------------------

//==============================================================================

} /* std */
//==============================================================================

#endif /* __SL_STDCPP_IMPL_LIMITS_HPP__ */

#endif /* __SL_STDCPP_IMPL_LIMITS_SPECIALIZATIONS_HPP__ */

//-<EOF>
