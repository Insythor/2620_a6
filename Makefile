#
# Makefile for CS 2620 Assignment 5
#
# Author: Tyler Justinen-Teite
# Mar. 20, 2020
#

PROJECT_DIR = a5
PROGRAM_USESTACK=	useStackProgram
PROGRAM_USEMAP= useMapProgram

CCC= g++
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

.PHONY: all
all:	$(PROGRAM_USESTACK) $(PROGRAM_USEMAP)
	$(PROGRAM_USESTACK) $(PROGRAM_USEMAP)

# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CCCFLAGS) -c $< $@

$(PROGRAM_USESTACK):	$(PROGRAM_USESTACK)
$(PROGRAM_USESTACK): testCSack.o CStack.o
	$(CCC) $(CCCFLAGS) $^ -o $@


$(PROGRAM_USEMAP): $(PROGRAM_USEMAP)
$(PROGRAM_USEMAP):	testCMap.o CMap.o
	$(CCC) $(CCCFLAGS) $^ -o $@
clean:
	rm -f *.o *~ *% $(PROGRAM_USESTACK) *# .#*

clean-all: clean
	rm -f $(PROGRAM_USESTACK)
