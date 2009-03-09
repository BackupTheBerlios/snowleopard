
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
#include <cstddef>
#include <fstream>
#include <iostream>

/*
 * Function outputs a file to standard output.
 */
void
output_file (char* filename)
{
	std::cout << "=====> " << filename << std::endl;
	
	std::ifstream ifs;

	ifs.open (filename);

	ifs.seekg (0, std::ios::end);
	std::size_t length = ifs.tellg ();
	ifs.seekg (0, std::ios::beg);

	char* buffer = new char[length];

	ifs.read (buffer, length);
	ifs.close ();

	std::cout.write (buffer, length);
	delete[] buffer;

	return;
}

/*
 * This program is a very simple version of cat. It prints the filenames given
 * to standard output.
 */
int
main (int argc, char** argv)
{
	if (argc < 2) {
		std::cerr << "Usage ex_7_4 <filename> ..." << std::endl;
		return 1;
	}

	while (*(++argv) != 0)
		output_file (*argv);

	return 0;
}

/*>- EOF -<*/
