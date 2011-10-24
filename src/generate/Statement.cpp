#include "Statement.h"
#include "Expression.h"

void Statement::print(std::ostream &out, unsigned int indentation)
{
    switch (type) {
    case 0:
        // Assigment statement
        for (int t = 0; t < indentation; ++t) out << "   ";
        std::cout << "x = 42;" << std::endl;
        
        break;
    case 1:
        // IF-statement
        for (int t = 0; t < indentation; ++t) out << "   ";
        std::cout << "if (";

        // Generate expression
        // TODO: Instantiate ConditionalExpression
        //Expression expr;
        //expr.print(out);
        out << "x < 2";
        
        // End if-statement
        std::cout << ") {" << std::endl;
        
        // Insert statement
        //Statement s(this->parent);
        //s.print(out, indentation + 1);
        
        // End block
        for (int t = 0; t < indentation; ++t) out << "   ";
        std::cout << "}" << std::endl;
        
        break;
    }
}


