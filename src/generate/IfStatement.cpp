#include <iostream>

#include "IfStatement.h"
#include "Expression.h"
#include "Statement.h"
#include "BlockStatement.h"


IfStatement::IfStatement(Scope* s) : Statement(s) {

	expression = Expression::generateExpression(this->scope);
    
    is_block = false;
	
	// Either a block with new statements, or a one-line if
	int r = rand() % 100;
	if(r < 80) {
		statement = new BlockStatement(scope);
		is_block = true;
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
	
	// Print block on same depth
	if (is_block) depth--;
	
	statement->print(out, depth + 1);
}
