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

useStackProgram : useStackProgram
useStackProgram : testCStack.o CStack.o
	$(CCC) $(CCCFLAGS) $^ -o $@

#Part two of the assignment
useMapProgram : useMapProgram
useMapProgram : CMatrixPro.o CMap.o
	$(CCC) $(CCCFLAGS) $^ -o $@	

	# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CCCFLAGS) -c $< $@

clean:
	rm -f *.o *~ *% $(PROGRAM_USESTACK) $(PROGRAM_USEMAP) *# .#*

clean-all: clean
	rm -f $(PROGRAM_USESTACK) $(PROGRAM_USEMAP)
