#include <iostream>
#include <cstdlib>
#include <time.h>

#include "Program.h"
#include "random.h"

int main(int argc, char* argv[]) {
    
    Random::seed(0x876544L);
    
    std::cout << "/*\tJSmith\t*/" << std::endl;
    
    srand ( time(NULL) );
    
	Program c;
	
	c.print(std::cout);
	
    return 0;

}
