#include <iostream>

#include "IfStatement.h"
#include "Expression.h"
#include "Statement.h"
#include "BlockStatement.h"


IfStatement::IfStatement(Scope* s) : Statement(s) {

	expression = Expression::generate_expression(this->scope);

	int r = rand() % 100;
	
	// Either a block with new statements, or a one-line if
	if(r < 80) {
		statement = new BlockStatement(scope);
	} else {
		statement = Statement::newRandomStatement(scope);
	}
}

void IfStatement::print(std::ostream& out, unsigned int depth){
	
	for (int t = 0; t < depth; ++t){
		out << "   ";
	}
	out << "if (";

	expression->print(out, 1);
	
	out << ")" << std::endl;
	
	statement->print(out, depth + 1);
}
