
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
#include <string>

/* Snow Leopard headers */
#include "cpp1_prg_0502_01.hpp"

/*
 * Function prints fighting.
 */
void wizard::fight ()
{
	using std::cout;
	using std::endl;

	cout << "Fighting!" << endl;
}

/*
 * Function prints talking.
 */
void wizard::talk ()
{
	using std::cout;
	using std::endl;

	cout << "Talking!" << endl;
}

/*
 * Function prints casting spell if there are enough magic points.
 */
void wizard::cast_spell ()
{
	using std::cout;
	using std::endl;

	if (magic_points_ > 4)
		cout << "Casting spell!" << endl;
	else
		cout << "Not enough magic points!" << endl;
}

/*
 * Function set the armor for this wizard.
 */
void wizard::set_armor (int armor)
{
	armor_ = armor;
}

/*
 * This function returns a copy of the name.
 */
std::string wizard::get_name ()
{
	return name_;
}

/*>- EOF -<*/
