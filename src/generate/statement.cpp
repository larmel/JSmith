#ifndef STATEMENT_CPP
#define STATEMENT_CPP

#include <string>
#include <cstdlib>
#include "function.cpp"

class Statement {
private:	
	Function *parent;
    int type;
	
public:
	

    Statement(Function *parent) 
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
	
	void print(std::ostream& out)
	{
	    
		out << "x = 1;" << std::endl;
	}
	
};

#endif
