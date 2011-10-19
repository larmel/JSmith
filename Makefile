#
# Makefile for JSmith
# Building both the code generator and test runner
#
# Note: make needs TAB for separating commands (as in before "g++")
#

COMPILER = g++

default: generate run

generate: src/generate/jsgen.cpp
	$(COMPILER) src/generate/*.cpp -o bin/generate
	
run: src/run/run.cpp
	$(COMPILER) src/run/run.cpp -o bin/run

clean:
	rm bin/run
	rm bin/generate

