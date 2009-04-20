
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

/* Standard C headers */
#include <cstring>

/* Snow Leopard headers */
#include "cpp1_prg_0703_01.hpp"

/*
 * constructor.
 */
string::string ()
{
	data_ = 0;
}

/*
 * constrcutor with data parameter.
 */
string::string (const char* rhs)
{
	int l = strlen (rhs);

	data_ = new char[l + 1];

	for (int i = 0; i < l; ++i)
		data_[i] = rhs[i];

	data_[l] = '\0';
}

/*
 * copy constructor.
 */
string::string (const string& rhs)
{
	data_ = 0;
	*this = rhs;
}

/*
 * destructor.
 */
string::~string ()
{
	delete[] data_;
	data_ = 0;
}

/*
 * operator= function. Assigns string.
 */
string&
string::operator= (const string& rhs)
{
	if (this == &rhs)
		return *this;

	int l = strlen (rhs.data_);

	delete[] data_;

	data_ = new char[l + 1];

	for (int i = 0; i < l; ++i)
		data_[i] = rhs.data_[i];

	data_[l] = '\0';

	return *this;
}

/*
 * operator[] function. Returns character in string.
 */
char&
string::operator[] (int i)
{
	return data_[i];
}

/*>- EOF -<*/
