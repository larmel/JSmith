#include <iostream>
#include "program.h"

int main(int argc, char* argv[]) {
    
    std::cout << "/*\tJSmith\t*/" << std::endl;
    
	Program c;
	
	c.print(std::cout);
	c.main(std::cout);
	
    return 0;

}
