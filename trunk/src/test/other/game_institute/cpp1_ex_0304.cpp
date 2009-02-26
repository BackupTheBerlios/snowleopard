
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
float arc_tangent (float, float);

/*
 * This program exercises the arc_tangent function.
 */
int
main ()
{
	using std::cout;
	using std::endl;

	/*
	 * using std::atanf2;
	 */
	
	cout << "Using arc_tangent" << endl;
	cout << "\tarc_tangent (4, 2)   = " << arc_tangent (4, 2) << endl;
	cout << "\tarc_tangent (5, -1)  = " << arc_tangent (5, -1) << endl;
	cout << "\tarc_tangent (-4, -6) = " << arc_tangent (-4, -6) << endl;
	cout << "\tarc_tangent (-6, 4)  = " << arc_tangent (-6, 4) << endl;
	
        /*
	 * cout << "Using atanf2" << endl;
	 * cout << "\tatanf2 (4, 2)   = " << atanf2 (4, 2) << endl;
	 * cout << "\tatanf2 (5, -1)  = " << atanf2 (5, -1) << endl;
	 * cout << "\tatanf2 (-4, -6) = " << atanf2 (-4, -6) << endl;
	 * cout << "\tatanf2 (-6, 4)  = " << atanf2 (-6, 4) << endl;
	 */
	
}

/*
 * Calculate the correct arc tangent.
 */
float
arc_tangent (float y, float x)
{
	/*
	 * using std::atanf;
	 */

	const double pi = 3.14159;
	
	if (x >= 0)
		return atanf (y / x) * (180 / pi);
	else
		return atanf (y / x) * (180 / pi) + 180;
}

/*>- EOF -<*/
