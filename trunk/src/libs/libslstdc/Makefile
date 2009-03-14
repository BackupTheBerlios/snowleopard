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
# File: /src/libs/libslstdc/Makefile
#
# Makefile for building and testing the Snow Leopard C++ libraries.
#/

#
# Variables
#
SL_INCLUDE = ../../include
SL_C_INCLUDE = ../../include/sl

INCLUDE_FLAGS = -I$(SL_C_INCLUDE) -I$(SL_INCLUDE)

STDC_INCLUDE = ../../include/sl/stdc

#
# All objects
#
ALL_OBJECTS = signal.o stddef.o stdlib.o string.o

CONFIG_HEADERS = $(SL_INCLUDE)/config/config.h

SIGNAL_DEPENDS = $(STDC_INCLUDE)/stddef.h $(STDC_INCLUDE)/stdlib.h \
		 $(STDC_INCLUDE)/signal.h

STDDEF_DEPENDS = $(STDC_INCLUDE)/stddef.h

STDLIB_DEPENDS = $(STDC_INCLUDE)/stddef.h $(STDC_INCLUDE)/stdlib.h \
		 $(STDC_INCLUDE)/signal.h

STRING_DEPENDS = $(STDC_INCLUDE)/string.h

#
# Libraries
#
DYNAMIC_LIBRARY = libslstdc.so
STATIC_LIBRARY = libslstdc.a

ALL_LIBRARIES = $(STATIC_LIBRARY) $(DYNAMIC_LIBRARY)

#
# Main targets
#
all: $(ALL_LIBRARIES)

libslstdc.a: $(ALL_OBJECTS)

libslstdc.so: $(ALL_OBJECTS)

signal.o: signal.c $(SIGNAL_DEPENDS) $(CONFIG_HEADERS)
	$(CC) -c $(CLFAGS) $(INCLUDE_FLAGS) -o $@ $<

stddef.o: stddef.c $(STDDEF_DEPENDS) $(CONFIG_HEADERS)
	$(CC) -c $(CLFAGS) $(INCLUDE_FLAGS) -o $@ $<

stdlib.o: stdlib.c $(STDLIB_DEPENDS) $(CONFIG_HEADERS)
	$(CC) -c $(CLFAGS) $(INCLUDE_FLAGS) -o $@ $<

string.o: string.c $(STRING_DEPENDS) $(CONFIG_HEADERS)
	$(CC) -c $(CLFAGS) $(INCLUDE_FLAGS) -o $@ $<

#
# Clean rule
#
clean:
	rm -f $(ALL_OBJECTS)   \
	rm -f $(ALL_LIBRARIES) 

#>- EOF
