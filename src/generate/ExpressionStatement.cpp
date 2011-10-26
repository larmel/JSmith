#include "ExpressionStatement.h"

ExpressionStatement::ExpressionStatement(Scope* s) : Statement(s){
    // Todo alternate between function call and other expressions
	expression = new CallExpression(s, 0);
}
void ExpressionStatement::print(std::ostream& out, unsigned int depth)
{
	expression->print(out, depth);
}
