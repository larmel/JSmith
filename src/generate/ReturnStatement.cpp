#include "ReturnStatement.h"
#include <iostream>
#include <vector>
#include "Expression.h"

ReturnStatement::ReturnStatement(Scope* s, unsigned int depth) : Statement(s, depth) {
	expression = Expression::generateExpression(s);
}

void ReturnStatement::print(std::ostream& out, unsigned int depth)
{
	for (int t = 0; t < depth; ++t){ 
		out << "   ";
	}
	out << "return ";
	expression->print(out, depth);
	out << ";" << std::endl;
}
