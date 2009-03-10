#-
# Copyright (c) 2009 Roel Sergeant.
# All rights reserved.
#
# This code is derived from software contributed to the Snow Leopard 
# project.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY 
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
# DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR 
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#/

#-
# File: /src/test/other/books/Makefile
#
# Makefile for other the programs of the game institute C++ courses. The name
# of each program is constructed as follows:
#
#     BOOK_[prg|ex]_CHEN
#
#       BOOK     = Book from which the program comes 
#		  ctmp = Template Metaprogramming (Abrahams, Gurtovoy)
#		  mcpd = Modern C++ design (Alexandrescu)
#                 tc_l = The C++ programming language (Stroustrup)
#                 tcio = The C++ standard IOStream library (Lanker, Kreft)
#                 tcpl = The C programming language (Richie, Kerninghan)
#                 tcsl = The C++ standard library (Jossitus)
#       [prg|ex] = prg = Sample program | ex = Exercise
#       CH       = Chapter number
#       EN       = Exercise number
#/

#
# All objects
#
ALL_OBJECTS = *.o

#
# All programs
#
TC_L_C1 = 

TC_L_C4 = tc_l_ex_0401

TC_L_C7 = tc_l_prg_0701 \
	  tc_l_ex_0701 tc_l_ex_0702 tc_l_ex_0703 tc_l_ex_0704

ALL_TC_L = $(TC_L_C1) $(TC_L_C4) $(TC_L_C7)

TCPL_C1 = tcpl_prg_0101

TCPL_C2 = 

TCPL_C3 = 

TCPL_C4 = 

ALL_TCPL = $(TCPL_C1) $(TCPL_C2) $(TCPL_C3) $(TCPL_C4)

TCSL_C2 = tcsl_prg_0201 tcsl_prg_0202 tcsl_prg_0203 tcsl_prg_0204 tcsl_prg_0205 \
	  tcsl_prg_0206 tcsl_prg_0207 tcsl_prg_0208 tcsl_prg_0209 tcsl_prg_0210 \
	  tcsl_prg_0211 tcsl_prg_0212 tcsl_prg_0213 tcsl_prg_0214 tcsl_prg_0215

TCSL_C3 = tcsl_prg_0301 tcsl_prg_0302 tcsl_prg_0303

ALL_TCSL = $(TCSL_C2) $(TCSL_C3)

ALL_PROGRAMS = $(ALL_TC_L) $(ALL_TCPL) $(ALL_TCSL)

#
# Main targets
#
all: $(ALL_PROGRAMS)

all_tc_l: $(ALL_TC_P)

all_tcpl: $(ALL_TCPL)

all_tcsl: $(ALL_TCSL)

# 
# Programs that require more than one source file.
#

#
# Suffix rule for compiling C++ sources
#
.cpp.o:
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.SUFFIXES: .cpp .o

#
# Suffix rule for compiling C sources
#
.c.o:
	$(CXX) -c $(CLFAGS) $(CPPFLAGS) -o $@ $<

.SUFFIXES: .c .o

#
# Clean rule
#
clean:
	rm -f $(ALL_PROGRAMS) ; \
	rm -f $(ALL_OBJECTS) ;  \
	rm -f *.core

#>- EOF
