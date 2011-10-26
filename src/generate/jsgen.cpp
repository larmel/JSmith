#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Program.h"
#include "Random.h"

/*
 * Usage:
 * > ./generate <seed>
 */
int main(int argc, char* argv[]) {
    
    unsigned long s = time(NULL);
    
    // Can give a seed as parameter to reconstruct some program
    // TODO: Error checking etc
    if (argc > 1) {
        unsigned long s = atol(argv[1]);
    }
    
    // This decides the whole generated source
    Random::seed( s );
    
    // Create an AST from subset of grammar
	Program c;
	
    std::cout << "/**********************************************/" << std::endl;
    std::cout << "/*  Automatically generated script by JSmith    " << std::endl;
    std::cout << "/*  Seed: " << s                                  << std::endl;
    std::cout << "/**********************************************/" << std::endl;
    
	// Print generated program
	c.print(std::cout);
	
    return 0;
}
