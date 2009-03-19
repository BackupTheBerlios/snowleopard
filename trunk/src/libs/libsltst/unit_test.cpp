
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

/* Snow Leopard Test headers */
#include <sl/test/unit_test.hpp>

/*
 * run function, call assert_true on the test function.
 */
void
sl::test::unit_test::run ()
{
	assert_true (test ());
}

/*
 * assert_true function (bool), just reports if a test has failed or not.
 * This is a wrapper for the real assert_true function.
 */
void
sl::test::unit_test::assert_true (bool ok)
{
	assert_true (ok, __FILE__, __LINE__, "No details specified");
}

/*
 * assert_true function (test_result), reports a test based on the data
 * received via the test_result object. This is wrapper for the real
 * assert_true function.
 */
void
sl::test::unit_test::assert_true (test_result result)
{
	assert_true (result.ok_, result.file_, result.line_, result.message_);
}

/*
 * assert_true function.
 */
void
sl::test::unit_test::assert_true (
	bool ok,
	const char* file,
	std::size_t line,
	const char* message
	)
{
	if (!ok)
	{
		std::cerr << "FAILURE: "
		          << file << ':'
		          << line << ": "
		          << message
		          << std::endl;
		counter_.failure ();
	}
	else
	{
		std::cout << "SUCCESS" << std::endl;
		counter_.success ();
	}
}

/*>- EOF -<*/
