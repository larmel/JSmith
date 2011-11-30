#include "Expression.h"
#include "PrimaryExpression.h"
#include "AddMulExpression.h"
#include "RelationalExpression.h"
#include "AssignmentExpression.h"
#include "CallExpression.h"
#include "Literal.h"
#include "RandomDiscreteDistribution.h"
#include "Random.h"
#include "Scope.h"
#include <cassert>

Expression::Expression(Scope *scope, int depth)
{
    assert(scope != NULL);
    this->scope = scope;
    this->depth = depth;
    this->parenthesis = false; // Random::flip_coin();
}

Expression *Expression::generateExpression(Scope *scope, int depth) {
    int p_terminal = 16*(3 + depth);
    Expression* expression = new Expression(scope, depth);

	// TODO: So far this only creates 1 new expression, not utilizing the list
	// Using several should work though.
    int expression_count = 1;
    for (int e = 0; e < expression_count; ++e) {

        RandomDiscreteDistribution r(4,
                30, // Relational Expression
                30, // ArithmeticExpression
                50, // CallExpression
                p_terminal);

        switch (r.getChosenIndex()) {
        case 0:
            expression->expressions.push_back(new RelationalExpression(scope, depth + 1));
            break;
        case 1:
            expression->expressions.push_back(new AddMulExpression(scope, depth + 1));
            break;
        case 2:
        {
            if (scope->getRandomFunctionVariable() != NULL) {
                expression->expressions.push_back(new CallExpression(scope, depth + 1));
                break;
            }
        }
        case 3:
            expression->expressions.push_back(new PrimaryExpression(scope, depth + 1));
            break;
        }
    }
    return expression;
}

Expression *Expression::generateExpressionForConditional(Scope *scope, int depth) {
	RandomDiscreteDistribution r (2, 95, 5);
	if(r.getChosenIndex() == 0) {
	    return new RelationalExpression(scope, depth);
	} else {
	    return Expression::generateExpression(scope, depth);
	}
}

void Expression::print(std::ostream &out) const
{
    if (this->parenthesis && this->expressions.size() > 1) out << "(";
    
    for (int i = 0; i < this->expressions.size(); i++) {
        out << *expressions[i];
        if (i < this->expressions.size()-1) {
            out << ",";
        }
    }
    if (this->parenthesis && this->expressions.size() > 1) out << ")";
}

std::ostream& operator<<(std::ostream& out, const Expression& e) {
    e.print(out);
    return out;
}

