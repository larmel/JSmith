
#include "Statement.h"
#include "Expression.h"

// CLASS STATEMENT

Statement::Statement(Function *parent) 
{
    this->parent = parent;
    this->type = rand() % 2;
}

void Statement::print(std::ostream &out)
{

    switch (type) {
        case 0:
            // Assigment statement
            std::cout << "x = 42;" << std::endl;
            
            break;
        case 1:
            // IF-statement
            std::cout << "if (";

            // Generate expression
            Expression expr;
            expr.print(out);
            
            // End if-statement
            std::cout << ") {" << std::endl;
            
            // Insert statement
            Statement s(this->parent);
            s.print(out);
            
            // End block
            std::cout << "}" << std::endl;
            
            break;
    }
    
}


