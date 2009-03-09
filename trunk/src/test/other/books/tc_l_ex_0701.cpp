
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

/*
 * Function f1, using references.
 */
void
f1 (char* str, int& int_ref)
{
	std::cout << "Str = " << str
		  << "; Int_ref  = " << int_ref << std::endl;
	int_ref++;
	return;
}

/*
 * Typedef for function pointer.
 */
typedef void (*f1_ptr_type) (char* str, int& int_ref);

/*
 * Function f2 using function pointer and reference.
 */
void
f2 (f1_ptr_type fun_parm, char* str, int& int_ref)
{
	std::cout << "Method with f1 as parm" << std::endl;
	fun_parm (str, int_ref);
	return;
}

/*
 * Function f3, returns a function pointer.
 */
f1_ptr_type
f3 ()
{
	return &f1;
}

/*
 * Function f4, returns a function pointer.
 */
f1_ptr_type
f4 (f1_ptr_type fun_parm, char* str, int& int_ref)
{
	fun_parm (str, int_ref);
	return fun_parm;
}

/*
 * This program demonstrates function pointers.
 */
int
main ()
{
	char* name = "Lena Katina";
	int x = 1;

	f1 (name, x);
	std::cout << "x after call = " << x << std::endl;

	f1_ptr_type f1_ptr = f1;

	std::cout << "Pointer to function assigned by &f1" << std::endl;
	f1_ptr (name, x);

	f2 (f1_ptr, name, x);

	std::cout << "Function pointer returned and called" << std::endl;
	f3 () (name, x);

	std::cout << "Function pointer as parameter and returned and called" << std::endl;
	f4 (f1_ptr, name, x) (name, x);

	return 0;
}

/*>- EOF -<*/
