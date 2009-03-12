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
# File: /src/test/other/game_institute/Makefile
#
# Makefile for other the programs of the game institute C++ courses. The name
# of each program is constructed as follows:
#
#     CCCC_[prg|ex]_CHEN
#
#       CCCC     = Course 
#                 cpp1 = C++ Course 1
#                 cpp2 = C++ Course 2
#                 gp_1 = Graphics Programming 1 (OpenGL/SDL instead of DirectX)
#                 gp_2 = Graphics Programming 2 (OpenGL/SDL instead of DirectX)
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
PROGRAMS_CPP1_L1 = cpp1_prg_0101 cpp1_prg_0102 cpp1_prg_0103 cpp1_prg_0104 \
		   cpp1_prg_0105 cpp1_prg_0106 cpp1_prg_0107 cpp1_prg_0108 \
		   cpp1_prg_0109 cpp1_prg_0110 cpp1_prg_0111 \
		   cpp1_ex_0101 cpp1_ex_0102 cpp1_ex_0103 cpp1_ex_0104     \
		   cpp1_ex_0105 cpp1_ex_0106

PROGRAMS_CPP1_L2 = cpp1_prg_0201 cpp1_prg_0202 cpp1_prg_0203 cpp1_prg_0204 \
		   cpp1_prg_0205 cpp1_prg_0206 cpp1_prg_0207 cpp1_prg_0208 \
		   cpp1_prg_0209 cpp1_prg_0210 cpp1_prg_0211 cpp1_prg_0212 \
		   cpp1_prg_0213 cpp1_prg_0214 cpp1_prg_0215 cpp1_prg_0216 \
		   cpp1_prg_0217 cpp1_prg_0218 \
		   cpp1_ex_0201 cpp1_ex_0202 cpp1_ex_0203 cpp1_ex_0204     \
		   cpp1_ex_0205 cpp1_ex_0206 cpp1_ex_0207 cpp1_ex_0208

PROGRAMS_CPP1_L3 = cpp1_prg_0301 cpp1_prg_0302 cpp1_prg_0303 cpp1_prg_0304 \
		   cpp1_prg_0305 cpp1_prg_0306 cpp1_prg_0307 cpp1_prg_0308 \
		   cpp1_prg_0309 \
		   cpp1_ex_0301 cpp1_ex_0302 cpp1_ex_0303 cpp1_ex_0304     \
		   cpp1_ex_0305 cpp1_ex_0306 cpp1_ex_0307 cpp1_ex_0308

PROGRAMS_CPP1_L4 = cpp1_prg_0401 cpp1_prg_0402 cpp1_prg_0403 cpp1_prg_0404 \
		   cpp1_prg_0405 cpp1_prg_0406 cpp1_prg_0407 cpp1_prg_0408 \
		   cpp1_prg_0409 cpp1_prg_0410 cpp1_prg_0411 cpp1_prg_0412 \
		   cpp1_ex_0402  cpp1_ex_0403 cpp1_ex_0404

CPP1_PRG_0501 = cpp1_prg_0501.o cpp1_prg_0501_01.o
CPP1_PRG_0501_HEADERS = cpp1_prg_0501_01.hpp

CPP1_PRG_0502 = cpp1_prg_0502.o cpp1_prg_0502_01.o
CPP1_PRG_0502_HEADERS = cpp1_prg_0502_01.hpp

CPP1_PRG_0503 = cpp1_prg_0503.o cpp1_prg_0503_01.o
CPP1_PRG_0503_HEADERS = cpp1_prg_0503_01.hpp

CPP1_PRG_0504 = cpp1_prg_0504.o cpp1_prg_0504_02.o cpp1_prg_0504_04.o \
		cpp1_prg_0504_05.o cpp1_prg_0504_06.o
CPP1_PRG_0504_HEADERS = cpp1_prg_0504_01.hpp cpp1_prg_0504_02.hpp \
			cpp1_prg_0504_03.hpp cpp1_prg_0504_04.hpp \
			cpp1_prg_0504_05.hpp cpp1_prg_0504_06.hpp

CPP1_EX_0501 = cpp1_ex_0501.o cpp1_ex_0501_02.o cpp1_ex_0501_04.o \
	       cpp1_ex_0501_05.o cpp1_ex_0501_06.o
CPP1_EX_0501_HEADERS = cpp1_ex_0501_01.hpp cpp1_ex_0501_02.hpp \
		       cpp1_ex_0501_03.hpp cpp1_ex_0501_04.hpp \
		       cpp1_ex_0501_05.hpp cpp1_ex_0501_06.hpp

PROGRAMS_CPP1_L5 = cpp1_prg_0501 cpp1_prg_0502 cpp1_prg_0503 cpp1_prg_0504 \
		   cpp1_ex_0501

ALL_PROGRAMS = $(PROGRAMS_CPP1_L1) $(PROGRAMS_CPP1_L2) $(PROGRAMS_CPP1_L3) \
	       $(PROGRAMS_CPP1_L4) $(PROGRAMS_CPP1_L5)

#
# Main targets
#
all: $(ALL_PROGRAMS)

cpp1_l1: $(PROGRAMS_CPP1_L1)

cpp1_l2: $(PROGRAMS_CPP1_L2)

cpp1_l3: $(PROGRAMS_CPP1_L3)

cpp1_l4: $(PROGRAMS_CPP1_L4)

cpp1_l5: $(PROGRAMS_CPP1_L5)

# 
# Programs that require more than one source file.
#
cpp1_prg_0501: $(CPP1_PRG_0501)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $(CPP1_PRG_0501)

$(CPP1_PRG_0501): $(CPP1_PRG_0501_HEADERS)

cpp1_prg_0502: $(CPP1_PRG_0502)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $(CPP1_PRG_0502)

$(CPP1_PRG_0502): $(CPP1_PRG_0502_HEADERS)

cpp1_prg_0503: $(CPP1_PRG_0503)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $(CPP1_PRG_0503)

$(CPP1_PRG_0503): $(CPP1_PRG_0503_HEADERS)

cpp1_prg_0504: $(CPP1_PRG_0504)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $(CPP1_PRG_0504)

$(CPP1_PRG_0504): $(CPP1_PRG_0504_HEADERS)

cpp1_ex_0501: $(CPP1_EX_0501)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $(CPP1_EX_0501)

$(CPP1_EX_0501): $(CPP1_EX_0501_HEADERS)

#
# Suffix rule for compiling C++ sources
#
.cpp.o:
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.SUFFIXES: .cpp .o

#
# Clean rule
#
clean:
	rm -f $(ALL_PROGRAMS) ; \
	rm -f $(ALL_OBJECTS)

#>- EOF
