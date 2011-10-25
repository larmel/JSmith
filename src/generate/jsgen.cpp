#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Program.h"


int main(int argc, char* argv[]) {
    
    std::cout << "/*\tJSmith\t*/" << std::endl;
    
    srand ( time(NULL) );
    
	Program c;
	
	c.print(std::cout);
	
    return 0;

}
