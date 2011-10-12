#include "statement.h"

// CLASS STATEMENT
	

Statement::Statement(Function *parent) 
{
    this->parent = parent;
    int type = rand() % 2;
    
    switch (type) {
        case 0: 
            // Assign something to one of the available variables
            
            
            break;
        case 1:
            // Create a new variable
            
            break;
    }

}

void Statement::print(std::ostream& out)
{
    
	out << "x = 31;" << std::endl;
}


