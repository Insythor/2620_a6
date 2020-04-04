#
# Makefile for CS 2620 Assignment 6
#
# Author: Tyler Justinen-Teite
# Apr. 4, 2020
#

PROJECT_DIR = a6
PROGRAM_USESTACK= useStack
PROGRAM_USEMAP= useMap

CCC= g++
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

.PHONY: all
all : $(PROGRAM_USESTACK) $(PROGRAM_USEMAP)
	$(PROGRAM_USESTACK) $(PROGRAM_USEMAP)

# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CCCFLAGS) -c $< $@

useStack : useStack
useStack : testCStack.o CStack.o
	$(CCC) $(CCCFLAGS) $^ -o $@

#Part two of the assignment
useMap : useMap
useMap : testCMap.o CMap.o
	$(CCC) $(CCCFLAGS) $^ -o $@	



clean:
	rm -f *.o *~ *% $(PROGRAM_USESTACK) $(PROGRAM_USEMAP) *# .#*

clean-all: clean
	rm -f $(PROGRAM_USESTACK) $(PROGRAM_USEMAP)
