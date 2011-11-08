#include "PrimaryExpression.h"
#include "Variable.h"
#include "Scope.h"
#include "RandomDiscreteDistribution.h"
#include "Literal.h"
#include <sstream>
#include <cstdio>

PrimaryExpression::PrimaryExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    RandomDiscreteDistribution r (2, 1, 1);

    switch (r.getChosenIndex()) {
    case 0:
        immidiate_value = "this";
        break;
    case 1:
        // TODO: Don't restrict on NUMBER_T. Might need extra parameter of what is needed?
        // Also, default fallback to this is pretty weak.
        Variable* var = scope->getRandomVariable(NUMBER_T);
        immidiate_value = (var == NULL) ? "this" : var->name;
    }
}

Expression* PrimaryExpression::generatePrimaryExpression(Scope* scope, int depth) {

    RandomDiscreteDistribution r(3, 1, 1, 1);
    switch (r.getChosenIndex()) {
    case 0:
        return new Literal(scope, depth);
    case 1:
    case 2:
        return new PrimaryExpression(scope, depth);
    }
}

void PrimaryExpression::print(std::ostream& out) const {
    out << this->immidiate_value;
}

std::ostream& operator<<(std::ostream& out, const PrimaryExpression& e) {
    e.print(out);
    return out;
}

