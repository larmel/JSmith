#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Program.h"
#include "Random.h"
#include <sys/time.h>

/*
 * Usage:
 * > ./generate <seed>
 */
int main(int argc, char* argv[]) {
         
    // Get the time seed
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long long s = time(NULL);
    unsigned long long time_seed = s*1000000+tv.tv_usec;
    
    // Can give a seed as parameter to reconstruct some program
    // TODO: Error checking etc
    if (argc > 1) {
        time_seed = atoll(argv[1]);
    }
    
    // This decides the whole generated source
    Random::seed( time_seed );
    
    // Create an AST from subset of grammar
	Program c;
	
    std::cout << "/********************************************************/" << std::endl;
    std::cout << "/*  JSmith (seed " << time_seed << ")" << std::endl;
    std::cout << "/********************************************************/" << std::endl;
    
	// Print generated program
	c.print(std::cout);
	
    return 0;
}
