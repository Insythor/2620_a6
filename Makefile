#
# Makefile for CS 2620 Assignment 6
#
# Author: Tyler Justinen-Teite
# Apr. 4, 2020
#

CCC= g++
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

.PHONY: all
all : testCStack testCMap

#Part one of the assignment
testCStack : testCStack.o
	$(CCC) $(CCCFLAGS) $^ -o $@

#Part two of the assignment
testCMap : testCMap.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule for compiling .cc to .o
%.o: %.cc
	$(CCC) $(CCCFLAGS) -c $< $@

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f CStack CMap
