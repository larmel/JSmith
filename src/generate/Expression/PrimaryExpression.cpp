#include "PrimaryExpression.h"
#include "Variable.h"
#include "Scope.h"
#include "RandomDiscreteDistribution.h"
#include "Literal.h"
#include <sstream>
#include <cstdio>

PrimaryExpression::PrimaryExpression(Scope* parent_scope, int depth, Type type) : Expression(parent_scope, depth, type) {
    var = NULL;
    RandomDiscreteDistribution r (2, 1, 1);

    switch (type) {
    case NUMBER_T:
    {
    	RandomDiscreteDistribution r (2, 1, 1);
    	if (r.getChosenIndex()==0)
    		var = scope->getRandomVariable(NUMBER_T);

    	if (r.getChosenIndex()==1 || var==NULL)
    		terminal_expr = new Literal(scope,0,NUMBER_T);

    }  break;
    case STRING_T:
    {
    	RandomDiscreteDistribution r (2, 1, 1);
    	if (r.getChosenIndex()==0)
    		var = scope->getRandomVariable(NUMBER_T);

    	if (r.getChosenIndex()==1 || var==NULL)
    		terminal_expr = new Literal(scope,0,NUMBER_T);

    } break;
    }
}

// TODO: Might need type specifier here. EDIT: Added type specifier
Expression* PrimaryExpression::generatePrimaryExpression(Scope* scope, int depth, Type type) {

    RandomDiscreteDistribution r(3, 1, 1, 1);
    switch (r.getChosenIndex()) {
    case 0:
        return new Literal(scope, depth, type);
    case 1:
    case 2:
        return new PrimaryExpression(scope, depth, type);
    }
}

void PrimaryExpression::print(std::ostream& out) const {
	if (var!=NULL) {
		out << *var;
	} else {
		out << *terminal_expr;
	}
}

std::ostream& operator<<(std::ostream& out, const PrimaryExpression& e) {
    e.print(out);
    return out;
}

