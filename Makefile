#
# Makefile for JSmith
# Building both the code generator and test runner
#
# Note: make needs TAB for separating commands (as in before "g++")
#

# Variables 'n shit
COMPILER := g++
CPP_FILES := $(wildcard src/generate/*.cpp)
H_FILES := $(wildcard src/generate/*.h)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

# Default action, compile all
default: generate jsmith

# To generate JSGEN:
generate: bin/generate
	
bin/generate: $(OBJ_FILES) $(H_FILES)
	$(COMPILER) -o $@ $(OBJ_FILES)

obj/%.o: src/generate/%.cpp $(H_FILES)
	$(COMPILER) -c -o $@ $<
	
	
# To generate jsmith (naively)	
jsmith: src/run/jsmith.cpp
	$(COMPILER) src/run/*.cpp -o bin/jsmith

clean:
	rm -f bin/*
	rm -f obj/*

