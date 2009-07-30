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
# File: /src/tools/slbld/Makefile
#
# Makefile for building the Snow Leopard C++ Build Tool.
#/

#
# Include files.
#
.include <../scripts/makefiles/config.mk>

#
# Variables.
#
PROGRAM = slbld

CXXFLAGS = -Wall -Wextra -g

DEBUG_CXXFLAGS = -g

SLBLD_INCLUDE = ../../include/sl/slbld

SL_INCLUDE = ../../include

#
# All objects.
#
ALL_OBJECTS = \
	main.o version.o

MAIN_DEPENDS = \
	${SLBLD_INCLUDE}/version.hpp

VERSION_DEPENDS = \
	${SLBLD_INCLUDE}/version.hpp

#
# Main targets
#
all: what ${PROGRAM}

${PROGRAM}: ${ALL_OBJECTS}
	${CXX} ${CXXFLAGS} -I${SL_INCLUDE} -o slbld ${ALL_OBJECTS}

main.o: main.cpp ${MAIN_DEPENDS}
	${CXX} -c ${CXXFLAGS} -I${SL_INCLUDE} -o $@ $<

version.o: version.cpp ${VERSION_DEPENDS}
	${CXX} -c ${CXXFLAGS} -I${SL_INCLUDE} -o $@ $<

what:
	(echo Building the Snow Leopard C++ Build Tool);

#
# Clean rule
#
clean:
	rm -f $(PROGRAM) ;     \
	rm -f $(ALL_OBJECTS) ; \
	rm -f *.core

#>- EOF
