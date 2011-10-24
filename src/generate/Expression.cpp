#include "Expression.h"

// CLASS EXPRESSION


Expression::Expression(Function *function) 
{
    this->function = function;
    
    int gen_type = rand() % 8;
    
    switch (gen_type) {
    case 0:
        // Expression
    break;
        
    
    case 1:
    break;
    
    }

}


void Expression::print(std::ostream &out)
{

    // TODO:
    
    out << "1 < 2";
}

