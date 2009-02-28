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
# File: /src/test/libstdc/Makefile
#
# Makefile for the Standard C Library test suite. The name of each program is 
# constructed as follows:
#
#     header_sequence
#
#       header   = C standard header tested 
#       sequence = Test sequence number (3 long numeric)
#
# If additional headers or source files are needed for a program, the main one
# is named as above, while other are suffixed with _sequence (2 long numeric).
# For example string_001_00.c is the first additional file needed by the
# test program string_001.c.
#/

#
# All objects
#
ALL_OBJECTS = *.o

#
# All programs
#
CWCHAR_PROGRAMS = cwchar_000

ALL_PROGRAMS = $(CWCHAR_PROGRAMS)

#
# Main targets
#
all: $(ALL_PROGRAMS)

cwchar: $(CWCHAR_PROGRAMS)

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
# Clean rule
#
clean:
	rm -f $(ALL_PROGRAMS) ; \
	rm -f $(ALL_OBJECTS)

#>- EOF
