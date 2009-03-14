
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

/*******************************************************************************
 * NOTE:
 *   If the compiler supports export, this is compiled into the standard
 *   library. If not it is included in the <algorithm> header.
 ******************************************************************************/

/*
 * all_of function template
 */
template<
	InputIterator Iter,
	Predicate<auto, Iter::value_type> Pred
	>
bool
std::all_of (Iter first, Iter last, Pred predicate)
{
	for (Iter i = first; i != last; ++i)
		if (!predicate (*i))
			return false;

	return true;
}

/*
 * any_of function template
 */
template<
	InputIterator Iter,
	Predicate<auto, Iter::value_type> Pred
	>
bool
std::any_of (Iter first, Iter last, Pred predicate)
{
	for (Iter i = first; i != last; ++i)
		if (predicate (*i))
			return true;

	return false;
}

/*
 * none_of function template
 */
template<
	InputIterator Iter,
	Predicate<auto, Iter::value_type> Pred
	>
bool
std::none_of (Iter first, Iter last, Pred predicate)
{
	for (Iter i = first; i != last; ++i)
		if (predicate (*i))
			return false;

	return true;
}

/*
 * for_each function template
 */
template<
	InputIterator Iter,
	Callable<auto, Iter::reference> Function
	>
Function
std::for_each (Iter first, Iter last, Function function)
{
	for (Iter i = first; i != last; ++i)
		function (*i);

	return function;
}

/*
 * find function template
 */
template<
	InputIterator Iter,
	typename Type
	>
Iter
std::find (Iter first, Iter last, const Type& value)
{
	for (Iter i = first; i != last; ++i)
		if (*i == value)
			return i;

	return last;
}

/*
 * find_if function template
 */
template<
	InputIterator Iter,
	Predicate<auto, Iter::value_type> Pred
	>
Iter
std::find_if (Iter first, Iter last, Pred predicate)
{
	for (Iter i = first; i != last; ++i)
		if (predicate (*i))
			return i;

	return last;
}

/*
 * find_if_not function template
 */
template<
	InputIterator Iter,
	Predicate<auto, Iter::value_type> Pred
	>
Iter
find_if_not (Iter first, Iter last, Pred predicate)
{
	for (Iter i = first, i != last; ++i)
		if (!predicate (*i))
			return i;

	return last;
}

/*>- EOF -<*/
