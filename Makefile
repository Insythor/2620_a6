#
# Makefile for CS 2620 Assignment 5
#
# Author: Tyler Justinen-Teite
# Mar. 20, 2020
#

PROJECT_DIR = a5
PROGRAM_USESTACK=	myUseStackProgram

CCC= g++
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

.PHONY: all
all:	$(PROGRAM_USESTACK)

# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CCCFLAGS) -c $< $@

#Part one of the assignment
$(PROGRAM_USESTACK) : $(PROGRAM_USESTACK)
	$(CCC) $(CCCFLAGS) -o $(PROGRAM_USESTACK) *.cc

useStack:	$(PROGRAM_USESTACK)

clean:
	rm -f *.o *~ *% $(PROGRAM_USESTACK) *# .#*

clean-all: clean
	rm -f $(PROGRAM_USESTACK)
