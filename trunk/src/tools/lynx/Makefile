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
# File: /src/tools/lynx/Makefile
#
# Makefile for building the Lynx typesetting system.
#/

#
# Variables
#
SL_INCLUDE = ../../include
LYNX_INCLUDE = ../../include/lynx

#
# All objects
#
ALL_OBJECTS = *.o

ALL_PROGRAMS = lynx lroff leqn lpic lrefer ltbl lsoelim

LYNX_OBJECTS = driver.o info.o main.o version.o
driver_HEADERS = $(LYNX_INCLUDE)/driver.hpp

LROFF_OBJECTS = 

LEQN_OBJECTS = 

LPIC_OBJECTS = 

LREFER_OBJECTS = 

LTBL_OBJECTS = 

LSOELIM_OBJECTS = 

#
# Main targets
# 
all: what $(ALL_PROGRAMS)

lynx: $(LYNX_OBJECTS)
	$(CXX) $(CFLAGS) $(CPPFLAGS) -o $@ $(LYNX_OBJECTS)

lroff: $(LROFF_OBJECTS)

leqn: $(LEQN_OBJECTS)

lpic: $(LPIQ_OBJECTS)

lrefer: $(LREFER_OBJECTS)

ltbl: $(LTABL_OBJECTS)

lsoelim: $(LSOELIM_OBJECTS)

what:
	(echo Building the Lynx Typesetting System);

#
# Suffix rule for building C++ sources
#
.cpp.o: 
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -I$(SL_INCLUDE) -o $@ $<

.SUFFIXES: .cpp .o

#
# Clean rule
#
clean:
	rm -f $(ALL_PROGRAMS) ; \
	rm -f $(ALL_OBJECTS)

#>- EOF
