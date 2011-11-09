#include "Expression.h"
#include "PrimaryExpression.h"
#include "AddMulExpression.h"
#include "RelationalExpression.h"
#include "CallExpression.h"
#include "Literal.h"
#include "RandomDiscreteDistribution.h"
#include <cassert>

Expression::Expression(Scope *scope, int depth, Type type)
{
    assert(scope != NULL);
    if (scope==NULL) {
        std::cerr << "No scope provided to Expression node";
        exit(1);
    }
    this->scope = scope;
    this->depth = depth;
    this->type = type;
    this->parenthesis = false;
}

Expression *Expression::generateExpression(Scope *scope, int depth, Type type) {

	// TODO: So far this only creates 1 new expression, not utilizing the list
	// Using several should work though.
	Expression *expression = new Expression(scope, depth, type);

	switch (type) {

	// If we want an expression of type NUMBER
	case NUMBER_T:
        {
            int gen_type = rand() % 100;
            Expression *subexpr = NULL;

            // Linear increasing probability for terminal expression nodes
            int p_terminal = 40 + 60*((double)depth/20);

            if (gen_type < p_terminal) // Generate a terminal node (PrimaryExpression)
            {
                // PrimaryExpression (actual variables)
                subexpr = new PrimaryExpression(scope, depth, NUMBER_T);
            }

            else  // Generate some sort of non-terminal node:
            {
                RandomDiscreteDistribution r (3, 40, 10, 1);

                switch (r.getChosenIndex())
                {
                    case 0:
                        subexpr = new AddMulExpression(scope, depth, NUMBER_T);
                        break;
                    case 1:
                        subexpr = Expression::generateExpression(scope, depth+1, NUMBER_T);
                        expression->parenthesis = true;
                        break;
                    case 2:
                        subexpr = new RelationalExpression(scope, depth, NUMBER_T);
                        break;
                }
            }

            assert(subexpr != NULL);
            expression->expressions.push_back(subexpr);
        }
        break;

	case STRING_T:
        {
            RandomDiscreteDistribution r (2, 10, 2);

            Expression *subexpr = NULL;
            std::cout << subexpr << "\n\n";

            switch(r.getChosenIndex())
            {
            case 0: // A string
                subexpr = new Literal(scope, depth, STRING_T);
                break;

            case 1: // Concatenation of two strings
                subexpr = new AddMulExpression(scope, depth, STRING_T);
                break;
            }

            assert(subexpr != NULL);
            expression->expressions.push_back(subexpr);
        }
        break;

	default:
        {
            std::cerr << "Expression type " << type << " is not implemented.\n\n";
            exit(1);
        }

	}

	assert(expression != NULL);
	return expression;
}

Expression *Expression::generateExpressionForConditional(Scope *scope, int depth, Type type) {
	RandomDiscreteDistribution r (2, 90, 10);
	if(r.getChosenIndex() == 0) {
	    return new RelationalExpression(scope, depth, type);
	} else {
	    return Expression::generateExpression(scope, depth, type);
	}
}

void Expression::print(std::ostream &out) const
{
    if (this->parenthesis) out << "(";
    
    for (int i = 0; i < this->expressions.size(); i++) {
        out << *expressions[i];
        if (i < this->expressions.size()-1) {
            out << ",";
        }
    }
    if (this->parenthesis) out << ")";
}

std::ostream& operator<<(std::ostream& out, const Expression& e) {
    e.print(out);
    return out;
}

