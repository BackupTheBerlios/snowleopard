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
# File: /src/tools/slci/Makefile
#
# Makefile for building the Snow Leopard C++ interpreter.
#/

#
# Variables
#
PROGRAM = slci

SLCI_INCLUDE = ../../include/sl/slci

SL_INCLUDE_PATH = ../../include

ALL_OBJECTS = binary_search.o driver.o error_handling.o info.o lexer.o main.o \
	      parser.o reader.o settings.o source_position.o token.o version.o

BINARY_SEARCH_DEPENDS = $(SLCI_INCLUDE)/binary_search.h

DRIVER_DEPENDS = $(SLCI_INCLUDE)/driver.h $(SLCI_INCLUDE)/parser.h \
		 $(SLCI_INCLUDE)/settings.h

ERROR_HANDLING_DEPENDS = $(SLCI_INCLUDE)/error_handling.h \
                         $(SLCI_INCLUDE)/source_position.h

INFO_DEPENDS = $(SLCI_INCLUDE)/info.h $(SLCI_INCLUDE)/version.h

LEXER_DEPENDS = $(SLCI_INCLUDE)/binary_search.h $(SLCI_INCLUDE)/lexer.h \
		$(SLCI_INCLUDE)/literal.h $(SLCI_INCLUDE)/preprocessor.h \
		$(SLCI_INCLUDE)/reader.h $(SLCI_INCLUDE)/source_position.h \
		$(SLCI_INCLUDE)/symbol_table.h $(SLCI_INCLUDE)/token.h

MAIN_DEPENDS = $(SLCI_INCLUDE)/driver.h $(SLCI_INCLUDE)/error_handling.h \
               $(SLCI_INCLUDE)/info.h $(SLCI_INCLUDE)/settings.h \
	       $(SLCI_INCLUDE)/source_position.h 

PARSER_DEPENDS = $(SLCI_INCLUDE)/lexer.h $(SLCI_INCLUDE)/literal.h \
		 $(SLCI_INCLUDE)/parser.h $(SLCI_INCLUDE)/reader.h  \
		 $(SLCI_INCLUDE)/source_position.h $(SLCI_INCLUDE)/token.h

READER_DEPENDS = $(SLCI_INCLUDE)/reader.h $(SLCI_INCLUDE)/source_position.h

SETTINGS_DEPENDS = $(SLCI_INCLUDE)/settings.h

SOURCE_POSITION_DEPENDS = $(SLCI_INCLUDE)/source_position.h

TOKEN_DEPENDS = $(SLCI_INCLUDE)/literal.h $(SLCI_INCLUDE)/token.h \
		$(SLCI_INCLUDE)/source_position.h

VERSION_DEPENDS = $(SLCI_INCLUDE)/version.h

#
# Main targets
#
all: what $(PROGRAM)

$(PROGRAM) : $(ALL_OBJECTS)
	$(CC) $(CFLAGS) -I$(SL_INCLUDE_PATH) -o slci $(ALL_OBJECTS)

binary_search.o: binary_search.c $(BINARY_SEARCH_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

driver.o: driver.c $(DRIVER_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

error_handling.o: error_handling.c $(ERROR_HANDLING_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

info.o: info.c $(INFO_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

lexer.o: lexer.c $(LEXER_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

main.o: main.c $(MAIN_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

parser.o: parser.c $(PARSER_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

reader.o: reader.c $(READER_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

settings.o: settings.c $(SETTINGS_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

source_position.o: source_position.c $(SOURCE_POSITION_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

token.o: token.c $(TOKEN_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

version.o: version.c $(VERSION_DEPENDS)
	$(CC) -c $(CFLAGS) -I$(SL_INCLUDE_PATH) -o $@ $<

what:
	(echo Building the Snow Leopard C++ Interpreter); 

#
# Clean rule
#
clean:
	rm -f $(PROGRAM) ; \
	rm -f $(ALL_OBJECTS)

#>- EOF
