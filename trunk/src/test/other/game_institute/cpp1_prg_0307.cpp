
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
 * This program shows some of the standard library provided math functions.
 */
int
main ()
{
	using std::cout;
	using std::endl;

	/*
	 * using std::ceilf;
	 * using std::cosf;
	 * using std::expf;
	 * using std::fabsf;
	 * using std::floorf;
	 * using std::logf;
	 * using std::powf;
	 * using std::sinf;
	 * using std::sqrtf;
	 */
	
	float pi = 3.1415f;
	float quarter_pi = pi / 4.0f;

	cout << "cos (0.0f)         = " << cosf (0.0f) << endl;
	cout << "sinf (quarter_pi)  = " << sinf (quarter_pi) << endl;
	cout << "sqrtf (2.0f)       = " << sqrtf (2.0f) << endl;
	cout << "logf (expf (1.0f)) = " << logf (expf (1.0f)) << endl;
	cout << "powf (2.0f, 3.0f)  = " << powf (2.0f, 3.0f) << endl;
	cout << "fabsf (-5.0f)      = " << fabsf (-5.0f) << endl;
	cout << "floorf (2.3f)      = " << floorf (2.3f) << endl;
	cout << "ceilf (2.3f)       = " << ceilf (2.3f) << endl;

}

/*>- EOF -<*/
