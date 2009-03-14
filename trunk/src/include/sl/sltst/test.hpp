
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

#ifndef _SL_SLTST_TEST_HPP_
#define _SL_SLTST_TEST_HPP_

/* Snow Leopard headers */
#include <sl/sltst/unit_test.hpp>

/*
 * SL_CREATE_TEST macro
 */
#define SL_CREATE_TEST(SL_TEST_NAME)   \
	class SL_TEST_NAME             \
	  : public sl::test::unit_test \
	{                              \
        public:                        \
               bool test ();           \
	};

/*
 * SL_TEST_CONDITION macro
 */
#define SL_TEST_CONDITION(SL_TEST_NAME, SL_CONDITION) \
	bool SL_TEST_NAME::test ()                    \
	{                                             \
	return (SL_CONDITION);                        \
	}

/*
 * SL_RUN_TEST macro
 */
#define SL_RUN_TEST(SL_TEST_NAME)   \
	int main ()                 \
	{                           \
	        SL_TEST_NAME test_; \
	        test_.run ();       \
	}

#endif /* !_SL_SLTST_TEST_HPP_ */

/*>- EOF -<*/
