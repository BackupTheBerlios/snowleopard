
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

/* Standard C++ headers */
#include <cmath>
#include <iostream>

/*
 * Point structure.
 */
struct point
{
	float x_;
	float y_;
	float z_;

	point (float x, float y, float z)
	    : x_ (x), y_ (y), z_ (z)
	{ }
};

/*
 * Function prototypes.
 */
void print_point (point);
float distance (point, point);

/*
 * This program calculates the 3D distance between points.
 */
int
main ()
{
	using std::cout;
	using std::endl;
	
	point p1(1, 2, 3);
	point p2(0, 0, 0);
	point p3(7, -4, 5);

	cout << "Distance between ";
	print_point (p1);
	cout << " and ";
	print_point (p2);
	cout << " = " << distance (p1, p2) << endl;

	cout << "Distance between ";
	print_point (p1);
	cout << " and ";
	print_point (p1);
	cout << " = " << distance (p1, p1) << endl;

	cout << "Distance between ";
	print_point (p1);
	cout << " and ";
	print_point (p3);
	cout << " = " << distance (p1, p3) << endl;
}

/*
 * Print a point.
 */
void print_point (point p)
{
	using std::cout;

	cout << '(' << p.x_ << ", " << p.y_ << ", " << p.z_ << ')';
}

/*
 * Calculate distance between points.
 */
float distance (point p1, point p2)
{
	/*
	 * using std::powf;
	 */

	/* Square of x2 - x1 */
	float p = powf (p2.x_ - p1.x_, 2);

	/* p + Square of y2 - y1 */
	p = p + powf (p2.y_ - p1.y_, 2);

	/* p + Square of z2 - z1 */
	p = p + powf (p2.z_ - p1.z_, 2);

	/* Square root of p */
	return sqrtf (p);

}

/*>- EOF -<*/
