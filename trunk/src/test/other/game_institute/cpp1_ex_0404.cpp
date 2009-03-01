
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
 * Function prototypes.
 */
bool quadratic_formula (float, float, float, float&, float&, float&, float&);

/*
 * This program calculates the root of quadratic equations.
 */
int
main ()
{
	using std::cout;
	using std::endl;
	
	float r1 = 0.0f;
	float i1 = 0.0f;
	float r2 = 0.0f;
	float i2 = 0.0f;

	if (!quadratic_formula (1, 2, 5, r1, i1, r2, i2))
		cout << "Coefficients a = 1, b = 2, c = 5 yield S1 = "
		     << r1 << " + " << i1 << "i, and S2 = "
		     << r2 << " + " << i2 << "i" << endl;
	else
		cout << "Coefficients a = 1, b = 2, c = 5 yield S1 = "
		     << r1 << " and S2 = " << r2 << endl;
	
}

/*
 * Calculate the root of quadratic equations. Return true if the roots have a
 * imaginary part.
 */
bool
quadratic_formula (
	float a, float b, float c,
	float& r1, float& i1, float& r2, float& i2
	)
{
	float discriminant = b * b  - 4 * a * c;

	if (discriminant < 0)
	{
		r1 = -b /2 * a;
		i1 = sqrtf (discriminant * -1) / 2 * a;
		r2 = r1;
		i2 = -(sqrtf (discriminant * -1)) / 2 * a;
		return false;
	}
	else
	{
		r1 = (-b + sqrtf (b * b - 4 * a * c))/ 2 * a;
		i1 = 0;
		r2 = (-b - sqrtf (b * b - 4 * a * c))/ 2 * a;
		i2 = 0;
		return true;
	}
}

/*>- EOF -<*/
