#include "IfStatement.h"
#include <iostream>
#include "Expression.h"

void IfStatement::print(std::ostream& out, unsigned int depth){
	
	for (int t = 0; t < depth; ++t) out << "   ";
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
	for (int t = 0; t < depth; ++t) out << "   ";
	std::cout << "}" << std::endl;
}