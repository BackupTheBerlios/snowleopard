
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
#include <cmath>
#include <iostream>

/* Snow Leopard headers */
#include "cpp1_prg_0702_01.hpp"

/*
 * vector3 default constructor.
 */
vector3::vector3 ()
		: x_ (0.0f), y_ (0.0f), z_ (0.0f)
{ }

/*
 * vector3 constructor (float array).
 */
vector3::vector3 (float coords[3])
		: x_ (coords[0]), y_ (coords[1]), z_ (coords[2])
{ }

/*
 * vector3 constructor (3 floats).
 */
vector3::vector3 (float x, float y, float z)
		: x_ (x), y_ (y), z_ (z)
{ }

/*
 * operator== function. Returns true if the given vector is equal to the
 * this vector, otherwise it returns false.
 */
bool
vector3::operator== (const vector3& rhs) const
{
	return x_ == rhs.x_
	    && y_ == rhs.y_
	    && z_ == rhs.z_;
}

/*
 * operator!= function. Tests if two vectors are unequal.
 */
bool
vector3::operator!= (const vector3& rhs) const
{
	return x_ != rhs.x_
	    && y_ != rhs.y_
	    && z_ != rhs.z_;
}

/*
 * operator+ function. Adds to the given vector to this vector and returns
 * a new vector containing the result.
 */
vector3
vector3::operator+ (const vector3& rhs)
{
	vector3 sum;
	sum.x_ = x_ + rhs.x_;
	sum.y_ = y_ + rhs.y_;
	sum.z_ = z_ + rhs.z_;

	return sum;
}

/*
 * operator- function. Subtracts the given vector from this vector and returns
 * a new vector containing the result.
 */
vector3
vector3::operator- (const vector3& rhs)
{
	vector3 dif;
	dif.x_ = x_ - rhs.x_;
	dif.y_ = y_ - rhs.y_;
	dif.z_ = z_ - rhs.z_;

	return dif;
}

/*
 * operator* function. Returns the product of a scalar and a vector.
 */
vector3
vector3::operator* (float scalar)
{
	vector3 p;
	p.x_ = x_ * scalar;
	p.y_ = y_ * scalar;
	p.z_ = z_ * scalar;

	return p;
}

/*
 * length function. Returns the magnitude of the vector.
 */
float
vector3::length ()
{
	using std::sqrt;

	return sqrt (x_ * x_ + y_ * y_ + z_ * z_);
}

/*
 * normalize function. Normalizes the vector.
 */
void
vector3::normalize ()
{
	float l = length ();

	x_ /= l;
	y_ /= l;
	z_ /= l;
}

/*
 * operator* function. Returns the dot-product of two vectors.
 */
float
vector3::operator* (const vector3& rhs)
{
	return x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_;
}

/*
 * operator float* function. Returns a pointer to x, so the user is able to use it
 * as an array.
 */
vector3::operator float* ()
{
	return &x_;
}

/*
 * operator<< function for vector3. Print the vector.
 */
std::ostream&
operator<< (std::ostream& os, vector3& v)
{
	os << "<" << v.x_ << ", " << v.y_ << ",  " << v.z_ << ">";

	return os;
}

/*
 * operator>> function for vector3. Allows the user to enter a vector.
 */
std::istream&
operator>> (std::istream& is, vector3& v)
{
	using std::cout;

	cout << "Enter x: ";
	is >> v.x_;
	cout << "Enter y: ";
	is >> v.y_;
	cout << "Enter z: ";
	is >> v.z_;

	return is;
}

/*>- EOF -<*/
