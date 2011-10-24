#include "Statement.h"
#include "Expression.h"
#include "VariableStatement.h"
#include "IfStatement.h"
/*
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
        Expression *e = Expression::generate_expression(this->scope);
        e->print(out, 1);
        
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
*/

Statement* Statement::newRandomStatement(Scope* x){
	int r = rand() % 2;
	if(r == 0){
		return new VariableStatement(x);
	}
	return new IfStatement(x);
	
}
