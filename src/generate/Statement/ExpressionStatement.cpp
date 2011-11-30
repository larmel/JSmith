#include "ExpressionStatement.h"
#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Expression.h"

ExpressionStatement::ExpressionStatement(Scope* s, int depth) : Statement(s, depth) {
    RandomDiscreteDistribution r(2, 1, 10);

    if (r.getChosenIndex() == 0) {
        expression = Expression::generateExpression(s, depth + 1);
    } else {
        expression = new AssignmentExpression(s, depth + 1);
    }
}

void ExpressionStatement::print(std::ostream& out)
{
	this->printIndentation(out);
	expression->print(out);
	out << ";" << std::endl;
}
