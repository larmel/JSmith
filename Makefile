#
# Makefile for JSmith
# Building both the code generator and test runner
#
# Note: make needs TAB for separating commands (as in before "g++")
#

COMPILER = g++

jsgen: src/jsgen/jsgen.cpp
	$(COMPILER) src/jsgen/jsgen.cpp -o bin/jsgen



