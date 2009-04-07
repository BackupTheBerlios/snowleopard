
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
#include <iostream>

/* Snow Leopard headers */
#include "cpp1_prg_0701_01.hpp"

/*
 * This program uses the vector class and exercises most of its methods.
 */
int
main ()
{
	using std::cout;
	using std::endl;
	
	/* 1: Construct 3 vectors */
	float coords[3] = {1.0f, 2.0f, 3.0f};

	vector3 u;
	vector3 v(coords);
	vector3 w(-5.0f, 2.0f, 0.0f);

	/* 2: Print the 3 vectors */
	cout << "u = ";
	u.print ();
	cout << "v = ";
	v.print ();
	cout << "w = ";
	w.print ();
	cout << endl;
	
	/* 3: u = v + w */
	u = v.add (w);
	cout << "u = ";
	u.print ();
	cout <<  endl;

	/* 4: v = v / ||v|| */
	v.normalize ();
	cout << "unit v = ";
	v.print ();
	cout << "length v = " << v.length () << endl;
	cout << endl;

	/* 5: dotP = u * w */
	float dotP = u.dot (w);
	cout << "dot product u w = " << dotP << endl;
	cout << endl;

	/* 6: convert to array representation */
	float* array = v.to_array ();

	/* 7: print out each element and verify with v */
	cout << "[0] = " << array[0] << ", "
	     << "[1] = " << array[1] << ", "
	     << "[2] = " << array[2] << endl;
	cout << endl;

	/* 8: create a new vector from user input */
	cout << "Input vector..." << endl;
	vector3 m;
	m.input ();
	cout << "m = ";
	m.print ();
	cout << endl;
}

/*>- EOF -<*/
