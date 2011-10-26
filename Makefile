#
# Makefile for JSmith
# Building both the code generator and test runner
#
# Note: make needs TAB for separating commands (as in before "g++")
#

COMPILER = g++

default: generate csmith

generate: src/generate/jsgen.cpp
	$(COMPILER) src/generate/*.cpp -o bin/generate
	
csmith: src/run/csmith.cpp
	$(COMPILER) src/run/*.cpp -o bin/csmith

clean:
	rm bin/csmith
	rm bin/generate

