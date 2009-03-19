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
SL_C_INCLUDE = ../../include/sl
SL_CPP_INCLUDE = ../../include/sl

INCLUDE_FLAGS = -I$(SL_C_INCLUDE) -I$(SL_CPP_INCLUDE) -I$(SL_INCLUDE)

STDC_INCLUDE = ../../include/sl/stdc
STDCPP_INCLUDE = ../../include/sl/stdcpp

#
# All objects
#
ALL_OBJECTS = algorithm.o csignal.o cstddef.o cstdlib.o cstring.o exception.o \
	      new.o utility.o

CONFIG_HEADERS = $(SL_INCLUDE)/config/config.hpp $(SL_INCLUDE)/config/config.h

ALGORITHM_DEPENDS = $(STDCPP_INCLUDE)/algorithm \
		    $(STDCPP_INCLUDE)/detail/non_modifying_sequence.ipp \
		    $(STDCPP_INCLUDE)/detail/min_max.ipp \
		    $(STDCPP_INCLUDE)/detail/swap.ipp

CSIGNAL_DEPENDS = $(STDCPP_INCLUDE)/csignal.hpp

CSTDDEF_DEPENDS = $(STDCPP_INCLUDE)/cstddef.hpp

CSTDLIB_DEPENDS = $(STDCPP_INCLUDE)/cstddef.hpp $(STDCPP_INCLUDE)/cstdlib.hpp

CSTRING_DEPENDS = $(STDCPP_INCLUDE)/cstddef.hpp $(STDCPP_INCLUDE)/cstring.hpp

EXCEPTION_DEPENDS = $(STDCPP_INCLUDE)/exception.hpp \
		    $(STDCPP_INCLUDE)/detail/exception.ipp

NEW_DEPENDS = $(STDCPP_INCLUDE)/cstddef.hpp $(STDCPP_INCLUDE)/new.hpp \
	      $(STDCPP_INCLUDE)/exception.hpp

UTILITY_DEPENDS = $(STDCPP_INCLUDE)/utility.hpp \
		  $(STDCPP_INCLUDE)/detail/rel_ops.ipp \
		  $(STDCPP_INCLUDE)/detail/forward_move.ipp \
		  $(STDCPP_INCLUDE)/detail/pair.ipp

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

algorithm.o: algorithm.cpp $(ALGORITHM_DEPENDS) $(CONFIG_HEADERS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -o $@ $<

csignal.o: csignal.cpp $(CSIGNAL_DEPENDS) $(CONFIG_HEADERS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -o $@ $<

cstddef.o: cstddef.cpp $(CSTDDEF_DEPENDS) $(CONFIG_HEADERS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -o $@ $<

cstdlib.o: cstdlib.cpp $(CSTDLIB_DEPENDS) $(CONFIG_HEADERS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -o $@ $<

cstring.o: cstring.cpp $(CSTRING_DEPENDS) $(CONFIG_HEADERS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -o $@ $<

exception.o: exception.cpp $(EXCEPTION_DEPENDS) $(CONFIG_HEADERS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -o $@ $<

new.o: new.cpp $(NEW_DEPENDS) $(CONFIG_HEADERS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -o $@ $<

utility.o: utility.cpp $(UTILITY_DEPENDS) $(CONFIG_HEADERS)
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) $(INCLUDE_FLAGS) -o $@ $<

#
# Clean rule
#
clean:
	rm -f $(ALL_OBJECTS)   \
	rm -f $(ALL_LIBRARIES) 

#>- EOF
