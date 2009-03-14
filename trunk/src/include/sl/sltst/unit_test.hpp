
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

#ifndef _SL_SLTST_UNIT_TEST_HPP_
#define _SL_SLTST_UNIT_TEST_HPP_

/* Standard C++ headers */
#include <cstddef>

/* Snow Leopard headers */
#include <sl/sltst/counter.hpp>

namespace sl {

namespace sltst {

/*
 * unit_test class
 */

	/* unit_test class */
       	class unit_test
	{
	public:
		virtual ~unit_test ()
		{ }

		void run ();

		virtual bool test () = 0;

	protected:
		struct test_result
		{
			bool ok_;
			const char* file_;
			std::size_t line_;
			const char* message_;
		};

	private:
		counter counter_;

		void assert_true (bool ok);
		void assert_true (test_result result);
		void assert_true (
			bool ok, const char* file, std::size_t line,
			const char* message
			);

	};

} /* sl::sltst */

} /* sl */

#endif /* !_SL_SLTST_UNIT_TEST_HPP_ */

/*>- EOF -<*/
