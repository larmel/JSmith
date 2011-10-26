#
# Makefile for JSmith
# Building both the code generator and test runner
#
# Note: make needs TAB for separating commands (as in before "g++")
#

COMPILER = g++

default: generate jsmith

generate: src/generate/jsgen.cpp
	$(COMPILER) src/generate/*.cpp -o bin/generate
	
jsmith: src/run/jsmith.cpp
	$(COMPILER) src/run/*.cpp -o bin/jsmith

clean:
	rm bin/jsmith
	rm bin/generate

