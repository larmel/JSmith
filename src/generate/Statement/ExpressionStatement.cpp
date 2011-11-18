#include "ExpressionStatement.h"
#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Expression.h"

ExpressionStatement::ExpressionStatement(Scope* s, int depth) : Statement(s, depth) {
    RandomDiscreteDistribution r(2, 1, 10);

    /*
     * Move all assignment expressions here. They could really be a part of the generic
     * expressions, but it is easier to just say statements like these get their own line.
     * foo = function() { ... } etc
     */
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
