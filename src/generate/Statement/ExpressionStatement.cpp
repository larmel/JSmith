#include "ExpressionStatement.h"
#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Expression.h"

ExpressionStatement::ExpressionStatement(Scope* s, unsigned int depth) : Statement(s, depth) {
    
    expression = Expression::generateExpression(s, 0);
}

void ExpressionStatement::print(std::ostream& out)
{
    for (int t = 0; t < depth; ++t) out << "   ";
	expression->print(out);
	out << ";" << std::endl;
}
