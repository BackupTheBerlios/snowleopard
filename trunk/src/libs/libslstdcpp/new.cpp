
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
#include <new>

/*
 * nothrow constant
 */
const std::nothrow_t std::nothrow;

/*
 * set_new_handler function
 */
std::new_handler
std::set_new_handler (std::new_handler handler) throw ()
{

}

/*
 * Standard new operator, throws bad_alloc
 */
void*
operator new (std::size_t size) throw (std::bad_alloc)
{

}

/*
 * Standard new operator, no throw
 */
void*
operator new (std::size_t size, const std::nothrow_t&) throw ()
{

}

/*
 * Standard delete operator
 */
void
operator delete (void* ptr) throw ()
{

}

/*
 * Standard delete operator, no throw
 */
void
operator delete (void* ptr, const std::nothrow_t&) throw ()
{

}

/*
 * Array new operator, throws bad_alloc
 */
void*
operator new[] (std::size_t size) throw (std::bad_alloc)
{

}

/*
 * Array new operator, no throw
 */
void*
operator new[] (std::size_t size) throw ()
{

}

/*
 * Array delete operator
 */
void
operator delete[] (void* ptr) throw ()
{

}

/*
 * Array delete operator, no throw
 */
void
operator delete[] (void* ptr, const std::nothrow_t&) throw ()
{

}

/*
 * Placement new operator
 */
void*
operator new (std::size_t size, void* ptr) throw ()
{

}

/*
 * Placement array new operator
 */
void*
operator new[] (std::size_t size, void* ptr) throw ()
{

}

/*
 * Placement delete operator
 */
void
operator delete (void* ptr, void*) throw ()
{

}

/*
 * Placement array delete operator
 */
void
operator delete[] (void* ptr, void*) throw ()
{

}

/*>- EOF -<*/
