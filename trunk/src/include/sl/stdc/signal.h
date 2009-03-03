
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

#ifndef _SL_STDC_IMPL_SIGNAL_H_
#define _SL_STDC_IMPL_SIGNAL_H_

/* Snow Leopard configuration header */
#include <sl/config/config.h>

/* Standard C headers */
#include <stddef.h>

/*
 * sig_atomic_t typedef
 */
typedef SL_ARCHITECTURE_ATOMIC_INT_TYPE sig_atomic_t;
//------------------------------------------------------------------------------

/*
 * signal_value enumeration
 */
enum signal_value {
  SIGINT = 2, 
  SIGILL = 4, 
  SIGABRT = 6, 
  SIGFPE = 8, 
  SIGSEGV = 11, 
  SIGTERM = 15
};

typedef enum signal_value signal_value;

/*
 * signal handling constants
 */
extern const int SIG_DFL;
extern const int SIG_IGN;
extern const int SIG_ERR;

/*
 * signal function
 *
 * <TODO>: Define signal function
 */

/*
 * raise function
 */
int raise (signal_value signal);

#endif /* !_SL_STDC_IMPL_SIGNAL_H_ */

/*>- EOF -<*/
