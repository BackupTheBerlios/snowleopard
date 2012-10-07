
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

#ifndef _SL_STDCPP_CONCEPTS_OPERATORS_HPP_
#define _SL_STDCPP_CONCEPTS_OPERATORS_HPP_

/*******************************************************************************
 * Is concepts.hpp included?
 */
#ifndef _SL_STDCPP_CONCEPTS_HPP_
# error <concepts_operators.hpp> included without <concepts.hpp>
#endif /* !_SL_STDCPP_CONCEPTS_HPP_ */
/*******************************************************************************
 */

namespace std {

/*
 * Operator Concepts
 */

	/* concept HasPlus */
	auto concept HasPlus<typename T, typename U>
	{
		typename result_type;
		result_type operator+ (const T&, const U&);
	}
	
	/* concept HasMinus */
	auto concept HasMinus<typename T, typename U>
	{
		typename result_type;
		result_type operator- (const T&, const U&);
	}

	/* concept HasMultiply */
	auto concept HasMultiply<typename T, typename U>
	{
		typename result_type;
		result_type operator* (const T&, const U&);
	}

	/* concept HasDivide */
	auto concept HasDivide<typename T, typename U>
	{
		typename result_type;
		result_type operator/ (const T&, const U&);
	}

	/* concept HasModulus */
	auto concept HasModules<typename T, typename U>
	{
		typename result_type;
		result_type operator% (const T&, const U&);
	}

	/* concept HasUnaryPlus */
	auto concept HasUnaryPlus<typename T>
	{
		typename result_type;
		result_type operator+ (const T&);
	}

	/* concept HasNegate */
	auto concept HasNegate<typename T>
	{
		typename result_type;
		result_type operator- (const T&);
	}

	/* concept HasLess */
	auto concept HasLess<typename T, typename U>
	{
		bool operator< (const T&, const U&);
	}

	/* concept HasGreater */
	auto concept HasGreater<typename T, typename U>
	{
		bool operator> (const T&, const U&);
	}

	/* concept HasLessEqual */
	auto concept HasLessEqual<typename T, typename U>
	{
		bool operator<= (const T&, const U&);
	}

	/* concept HasGreaterEqual */
	auto concept HasGreaterEqual<typename T, typename U>
	{
		bool operator>= (const T&, const U&);
	}

	/* concept HasEqualTo */
	auto concept HasEqualTo<typename T, typename U>
	{
		bool operator== (const T&, const U&);
	}

	/* concept HasNotEqualTo */
	auto concept HasNotEqualTo<typename T, typename U>
	{
		bool operator!= (const T&, const U&);
	}

	/* concept HasLogicalAnd */
	auto concept HasLogicalAnd<typename T, typename U>
	{
		bool operator&& (const T&, const U&);
	}

	/* concept HasLogicalOr */
	auto concept HasLogicalOr<typename T, typename U>
	{
		bool operator|| (const T&, const U&);
	}

	/* concept HasLogicalNot */
	auto concept HasLogicalNot<typename T>
	{
		bool operator! (const T&);
	}

	/* concept HasBitAnd */
	auto concept HasBitAnd<typename T, typename U>
	{
		typename result_type;
		result_type operator& (const T&, const U&);
	}

	/* concept HasBitOr */
	auto concept HasBitOr<typename T, typename U>
	{
		typename result_type;
		result_type operator| (const T&, const U&);
	}

	/* concept HasBitXor */
	auto concept HasBitXor<typename T, typename U>
	{
		typename result_type;
		result_type operator^ (const T&, const U&);
	}

	/* concept HasComplement */
	auto concept HasComplement<typename T>
	{
		typename result_type;
		result_type operator~ (const T&);
	}

	/* concept HasLeftShift */
	auto concept HasLeftShift<typename T, typename U>
	{
		typename result_type;
		result_type operator<< (const T&, const U&);
	}

	/* concept HasRightShift */
	auto concept HasRightShift<typename T, typename U>
	{
		typename result_type;
		result_type operator>> (const T&, const U&);
	}

	/* concept HasDereference */
	auto concept HasDereference<typename T>
	{
		typename result_type;
		result_type operator* (T&&);
	}

	/* concept HasAddressOf */
	auto concept HasAddressOf<typename T>
	{
		typename result_type;
		result_type operator& (T&);
	}

	/* concept HasSubscript */
	auto concept HasSubscript<typename T, typename U>
	{
		typename result_type;
		result_type operator[] (T&&, const U&);
	}

	/* concept Callable */
	auto concept Callable<typename F, typename... Args>
	{
		typename result_type;
		result_type operator() (F&&, Args...);
	}

	/* concept HasAssign */
	auto concept HasAssign<typename T, typename U>
	{
		typename result_type;
		result_type T::operator= (U);
	}

	/* concept HasPlusAssign */
	auto concept HasPlusAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator+= (T&, U);
	}

	/* concept HasMinusAssign */
	auto concept HasMinusAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator-= (T&, U);
	}

	/* concept HasMultiplyAssign */
	auto concept HasMultiplyAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator*= (T&, U);
	}

	/* concept HasDivideAssign */
	auto concept HasDivideAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator/= (T&, U);
	}

	/* concept HasModulusAssign */
	auto concept HasModulusAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator%= (T&, U);
	}

	/* concept HasBitAndAssign */
	auto concept HasBitAndAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator&= (T&, U);
	}

	/* concept HasBitOrAssign */
	auto concept HasBitOrAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator|= (T&, U);
	}

	/* concept HasBitXorAssign */
	auto concept HasBitXorAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator^= (T&, U);
	}

	/* concept HasLeftShiftAssign */
	auto concept HasLeftShiftAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator<<= (T&, U);
	}

	/* concept HasRightShiftAssign */
	auto concept HasRightShiftAssign<typename T, typename U>
	{
		typename result_type;
		result_type operator>>= (T&, U);
	}

	/* concept HasPreincrement */
	auto concept HasPreincrement<typename T>
	{
		typename result_type;
		result_type operator++ (T&);
	}

	/* concept HasPostincrement */
	auto concept HasPostincrement<typename T>
	{
		typename result_type;
		result_type operator++ (T&, int);
	}

	/* concept HasPredecrement */
	auto concept HasPredecrement<typename T>
	{
		typename result_type;
		result_type operator-- (T&);
	}

	/* concept HasPostdecrement */
	auto concept HasPostdecrement<typename T>
	{
		typename result_type;
		result_type operator-- (T&, int);
	}

	/* concept HasComma */
	auto concept HasComma<typename T, typename U>
	{
		typename result_type;
		result_type operator, (const T&, const U&);
	}
	
} /* std */

#endif /* !_SL_STDCPP_CONCEPTS_OPERATORS_HPP_ */

/*>- EOF -<*/

