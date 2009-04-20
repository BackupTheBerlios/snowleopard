
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

#ifndef _SL_TEST_OTHER_GAME_INSTITUTE_CPP1_PRG_0702_01_HPP_
#define _SL_TEST_OTHER_GAME_INSTITUTE_CPP1_PRG_0702_01_HPP_

/* Standard C++ headers */
#include <iostream>

/*
 * Range structure.
 */
class vector3
{
public:
	vector3 ();
	vector3 (float[3]);
	vector3 (float, float, float);

	bool operator== (const vector3&) const;
	bool operator!= (const vector3&) const;

	vector3 operator+ (const vector3& rhs);
	vector3 operator- (const vector3& rhs);
	vector3 operator* (float scalar);
	float operator* (const vector3& rhs);
	
	float length ();

	void normalize ();

	operator float* ();

	float x_;
	float y_;
	float z_;

	friend std::istream& operator>> (std::istream&, vector3&);
	friend std::ostream& operator<< (std::ostream&, vector3&);
};

/*
 * operator<< function for vector3. Prints vector.
 */
std::ostream& operator<< (std::ostream& os, vector3& v);

/*
 * operator>> function for vector3. Input vector.
 */
std::istream& operator>> (std::istream& is, vector3& v);

#endif /* !_SL_TEST_OTHER_GAME_INSTITUTE_CPP1_PRG_0702_01_HPP_ */

/*>- EOF -<*/
