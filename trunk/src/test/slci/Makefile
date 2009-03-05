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
# File: /src/test/slci/Makefile
#
# This Makefile is for testing the Snow Leopard C++ Interpreter. It contains
# programs that are run through the slci program. The programs are named as 
# follows.
#
#     type_sequence_subject
#
#       type     = Type of test program.
#                 err - Test error reporting
#                 lng - Test language features
#                 prg - Test interpreter program
#                 run - Test program runs
#       sequence = Sequence number of the test
#       subject  = Subject of the test  
#/

#
# All objects
#
ALL_OBJECTS = *.o

#
# All programs
#
ALL_ERROR_REPORTING =

ALL_LANGUAGE = 

ALL_INTERPRETER = 

ALL_PROGRAMS = run_1_main_return_success run_2_main_return_failure

ALL_TESTS = $(ALL_ERROR_REPORTING) $(ALL_LANGUAGE) $(ALL_INTERPRETER) \
	    $(ALL_PROGRAMS)

#
# Required tools
#
REQUIRED_TOOLS = slci sltst

#
# Main targets
#
all: $(REQUIRED_TOOLS) $(ALL_TESTS)

error_reporting: $(REQUIRED_TOOLS) $(ALL_ERROR_REPORTING)

language: $(REQUIRED_TOOLS) $(ALL_LANGUAGE)

interpreter: $(REQUIRED_TOOLS) $(ALL_INTERPRETER)

programs: $(REQUIRED_TOOLS) $(ALL_PROGRAMS)

# 
# Programs that require more than one source file.
#

#
# Build required tools.
#
sltst:
	(cd ../../tools/sltst ; ${MAKE} all);

slci: 
	(cd ../../tools/slci ; ${MAKE} all);

#
# Suffix rule for compiling C++ sources
#
.c.o:
	$(CXX) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.SUFFIXES: .c .o

#
# Clean rule
#
clean:
	rm -f $(ALL_PROGRAMS) ; \
	rm -f $(ALL_OBJECTS)

#>- EOF
