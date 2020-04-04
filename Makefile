#
# Makefile for CS 2620 Assignment 6
#
# Author: Tyler Justinen-Teite
# Apr. 4, 2020
#

PROJECT_DIR = a6
PROGRAM_USESTACK= CStack
PROGRAM_USEMAP= CMap

CCC= g++
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

.PHONY: all
all : useStack useMap

#Part one of the assignment
CStack : CStack
CStack : testCStack.o
	$(CCC) $(CCCFLAGS) $^ -o $@

#Part two of the assignment
CMap : CMap
CMap : testCMap.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CCCFLAGS) -c $< $@

clean:
	rm -f *.o *~ *% $(PROGRAM_USESTACK) $(PROGRAM_USEMAP) *# .#*

clean-all: clean
	rm -f CStack CMap
