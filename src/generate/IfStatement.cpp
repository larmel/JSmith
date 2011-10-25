#include "IfStatement.h"
#include <iostream>
#include "Expression.h"
#include "Statement.h"
#include "BlockStatement.h"

void IfStatement::print(std::ostream& out, unsigned int depth){
	
	for (int t = 0; t < depth; ++t){
		out << "   ";
	}
	std::cout << "if (";

	// Generate expression
	Expression *e = Expression::generate_expression(this->scope);
	e->print(out, 1);
	
	std::cout << ")" << std::endl;
	
	// Either a block with new statements, or a one-line if
	
	int r = rand() % 100;
	Statement* q;
	
	if(r < 80){
		q = new BlockStatement(scope);
		q->print(out, depth);
	}else{
		q = Statement::newRandomStatement(scope);
		q->print(out, depth+1);
	}
	
}
