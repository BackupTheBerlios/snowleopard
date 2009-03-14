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
# File: /src/libs/libslstdcpp/Makefile
#
# Makefile for building and testing the Snow Leopard C++ libraries.
#/

#
# Variables
#
SL_INCLUDE = ../../include

SL_STDCPP_INCLUDE = ../../include/sl

#
# All objects
#
ALL_OBJECTS = algorithm.o csignal.o cstddef.o cstdlib.o cstring.o

ALGORITHM_DEPENDS = $(SL_STDCPP_INCLUDE)/algorithm \
		    $(SL_INCLUDE)/sl/stdcpp/detail/non_modifying_sequence.ipp \
		    $(SL_INCLUDE)/sl/stdcpp/detail/min_max.ipp \
		    $(SL_INCLUDE)/sl/stdcpp/detail/swap.ipp

CSIGNAL_DEPENDS = $(SL_STDCPP_INCLUDE)/csignal

CSTDDEF_DEPENDS = $(SL_STDCPP_INCLUDE)/cstddef

CSTDLIB_DEPENDS = $(SL_STDCPP_INCLUDE)/cstddef $(SL_STDCPP_INCLUDE)/cstdlib

CSTRING_DEPENDS = $(SL_STDCPP_INCLUDE)/cstddef $(SL_STDCPP_INCLUDE)/cstring

#
# Libraries
#
DYNAMIC_LIBRARY = libslstdcpp.so
STATIC_LIBRARY = libslstdcpp.a

ALL_LIBRARIES = $(STATIC_LIBRARY) $(DYNAMIC_LIBRARY)

#
# Main targets
#
all: $(ALL_LIBRARIES)

libslstdcpp.a: $(ALL_OBJECTS)

libslstdcpp.so: $(ALL_OBJECTS)

algorithm.o: algorithm.cpp $(ALGORITHM_DEPENDS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -I$(SL_INCLUDE) -I$(SL_STDCPP_INCLUDE) -o $@ $<

csignal.o: csignal.cpp $(CSIGNAL_DEPENDS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -I$(SL_INCLUDE) -I$(SL_STDCPP_INCLUDE) -o $@ $<

cstddef.o: cstddef.cpp $(CSTDDEF_DEPENDS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -I$(SL_INCLUDE) -I$(SL_STDCPP_INCLUDE) -o $@ $<

cstdlib.o: cstdlib.cpp $(CSTDLIB_DEPENDS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -I$(SL_INCLUDE) -I$(SL_STDCPP_INCLUDE) -o $@ $<

cstring.o: cstring.cpp $(CSTRING_DEPENDS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -I$(SL_INCLUDE) -I$(SL_STDCPP_INCLUDE) -o $@ $<

#
# Clean rule
#
clean:
	rm -f $(ALL_OBJECTS)   \
	rm -f $(ALL_LIBRARIES) 

#>- EOF
