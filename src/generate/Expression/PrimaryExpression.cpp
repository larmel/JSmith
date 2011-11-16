#include "PrimaryExpression.h"
#include "Variable.h"
#include "Scope.h"
#include "RandomDiscreteDistribution.h"
#include "Literal.h"
#include <sstream>
#include <cstdio>

PrimaryExpression::PrimaryExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    RandomDiscreteDistribution d(3,
            1, // Identifier
            5, // Literal
            0  // this
            );

    variable = NULL;
    literal = NULL;

    switch (d.getChosenIndex()) {
    case 0:
        variable = scope->getRandomVariable(NUMBER_T);
        if (variable != NULL) break;
    case 1:
        literal = new Literal();
        break;
    default:
        ; // When both variables are null, print 'this'
    }
}

void PrimaryExpression::print(std::ostream& out) const {
	if (variable != NULL) {
		out << *variable;
	} else if (literal != NULL) {
		out << *literal;
	} else {
	    out << "this";
	}
}

std::ostream& operator<<(std::ostream& out, const PrimaryExpression& e) {
    e.print(out);
    return out;
}

