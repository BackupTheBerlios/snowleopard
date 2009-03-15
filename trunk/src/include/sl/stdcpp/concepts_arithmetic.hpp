
/*-
 * Copyright (c) 2009 Roel Sergeant.
 * All rights reserved.
 *
 * This code is derived from software contributed to the Snow Leopard
 * project.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _SL_STDCPP_CONCEPTS_ARITHMETIC_HPP_
#define _SL_STDCPP_CONCEPTS_ARITHMETIC_HPP_

/*******************************************************************************
 * Is concepts.hpp included?
 */
#ifndef _SL_STDCPP_CONCEPTS_HPP_
# error <concepts_arithmetic.hpp> included without <concepts.hpp>
#endif /* !_SL_STDCPP_CONCEPTS_HPP_ */
/*******************************************************************************
 */

namespace std {

/*
 * Arithmetic Concepts
 */

	/* concept ArithmeticLike */
	concept ArithmeticLike<typename T>
	  : Regular<T>,
	    LessThanComparable<T>,
	    HasUnaryPlus<T>, HasNegate<T>,
	    HasPlus<T, T>, HasMinus<T, T>, HasMultiply<T, T>, HasDivide<T, T>,
	    HasPreincrement<T>, HasPostincrement<T>, HasPredecrement<T>,
	    HasPostdecrement<T>,
	    HasPlusAssign<T, const T&>, HasMinusAssign<T, const T&>,
	    HasMultiplyAssign<T, const T&>, HasDivideAssign<T, const T&>
	{
		explicit T::T (intmax_t);
		explicit T::T (uintmax_t);
		explicit T::T (long double);

		requires Convertible<HasUnaryPlus<T>::result_type, T>
		    && Convertible<HasNegate<T>::result_type, T>
		    && Convertible<HasPlus<T, T>::result_type, T>
		    && Convertible<HasMinus<T, T>::result_type, T>
		    && Convertible<HasMultiply<T, T>::result_type, T>
		    && Convertible<HasDivide<T, T>::result_type, T>
		    && SameType<HasPreincrement<T>::result_type, T&>
		    && SameType<HasPostincrement<T>::result_type, T>
		    && SameType<HasPredecrement<T>::result_type, T&>
		    && SameType<HasPostdecrement<T>::result_type, T>
		    && SameType<HasPlusAssign<T, const T&>::result_type, T&>
		    && SameType<HasMinusAssign<T, const T&>::result_type, T&>
		    && SameType<HasMultiplyAssign<T, const T&>::result_type, T&>
		    && SameType<HasDivideAssign<T, const T&>::result_type, T&>;
	}

	/* concept IntegralLike */
	concept IntegralLike<typename T>
	  : ArithmeticLike<T>,
	    HasComplement<T>,
	    HasModulus<T, T>, HasBitAnd<T, T>, HasBitOr<T, T>, HasBitXor<T, T>,
	    HasLeftShift<T, T>, HasRightShift<T, T>,
	    HasModulusAssign<T, const T&>,
	    HasLeftShiftAssign<T, const T&>, HasRightShiftAssign<T, const T&>,
	    HasBitAndAssign<T, const T&>, HasBitOrAssign<T, const T&>,
	    HasBitXorAssign<T, const T&>
	{
		requires Convertible<HasComplement<T>::result_type, T>
		    && Convertible<HasModulus<T, T>::result_type, T>
		    && Convertible<HasBitAnd<T, T>::result_type, T>
		    && Convertible<HasBitOr<T, T>::result_type, T>
		    && Convertible<HasBitXor<T, T>::result_type, T>
		    && Convertible<HasLeftShift<T, T>::result_type, T>
		    && Convertible<HasRightShift<T, T>::result_type, T>
		    && SameType<HasModulusAssign<T, const T&>::result_type, T&>
		    && SameType<HasLeftShiftAssign<T, const T&>::result_type, T&>
		    && SameType<HasRightShiftAssign<T, const T&>::result_type, T&>
		    && SameType<HasBitAndAssign<T, const T&>::result_type, T&>
		    && SameType<HasBitOrAssign<T, const T&>::result_type, T&>
		    && SameType<HasBitXorAssign<T, const T&>::result_type, T&>
		
        }

	/* concept SignedIntegralLike */
	concept SignedIntegralLike<typename T>
	  : IntegralLike<T>
	{ }

	/* concept UnsignedIntegralLike */
	concept UnsignedIntegralLike<typename T>
	  : IntegralLike<T>
	{ }

	/* concept FloatingPointLike */
	concept FloatingPointLike<typename T>
	  : ArithmeticLike<T>
	{ }
	
} /* std */

#endif /* !_SL_STDCPP_CONCEPTS_ARITHMETIC_HPP_ */

/*>- EOF -<*/
