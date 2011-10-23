#include "expression.h"

// CLASS EXPRESSION


Expression::Expression(Context c) 
{
    gen_type = rand() % 8;
    
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

    // TODO: Logic for inserting a decent expression 

    print op1;
    print operand;
    print op2;
    
    out << "1 < 2";


}

