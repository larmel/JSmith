#
# Makefile for JSmith
# Building both the code generator and test runner
#
# Note: make needs TAB for separating commands (as in before "g++")
#
# After adding subdirs, object stuff is fucked up
# g++ src/generate/*.cpp src/generate/Statement/*.cpp src/generate/Expression/*.cpp -Isrc/generate/Statement -Isrc/generate/Expression -Isrc/generate
#

# Variables 'n shit
COMPILER := g++
CPP_FILES := $(wildcard src/generate/*.cpp src/generate/Expression/*.cpp src/generate/Statement/*.cpp)
H_FILES := $(wildcard src/generate/*.h src/generate/Expression/*.h src/generate/Statement/*.h)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

# Default action, compile all
default: generate jsmith

# To generate JSGEN:
generate: bin/generate
	
#bin/generate: $(OBJ_FILES) $(H_FILES)
#	$(COMPILER) -o $@ $(OBJ_FILES) -Isrc/generate/Expression/ -Isrc/generate/Statement/ -Isrc/generate
	
bin/generate: 
	$(COMPILER) -o bin/generate $(CPP_FILES) -Isrc/generate/Expression/ -Isrc/generate/Statement/ -Isrc/generate

#obj/%.o: src/generate/%.cpp $(H_FILES)
#	$(COMPILER) -c -o $@ $< -Isrc/generate/Expression/ -Isrc/generate/Statement/ -Isrc/generate
	
	
# To generate jsmith (naively)	
jsmith: src/run/jsmith.cpp
	$(COMPILER) src/run/*.cpp -o bin/jsmith

clean:
	rm -f bin/*
	rm -f obj/*

