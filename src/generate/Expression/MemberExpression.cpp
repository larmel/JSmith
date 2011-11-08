#include "MemberExpression.h"
#include "RandomDiscreteDistribution.h"
#include "PrimaryExpression.h"
#include "Scope.h"
#include "Variable.h"

MemberExpression::MemberExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    RandomDiscreteDistribution r = RandomDiscreteDistribution(3, 1, 1, 1);
    is_primary = r.getChosenIndex() == 0;
    is_function = r.getChosenIndex() == 1;
    is_identifier = r.getChosenIndex() == 2;

    if (is_primary) {
        this->expression = PrimaryExpression::generatePrimaryExpression(scope, depth);
    }

    if (is_function) {
        this->expression = PrimaryExpression::generatePrimaryExpression(scope, depth); // TODO
    }

    if (is_identifier) {
        // Probably want to limit the number of possibilities here.
        // Most natural is this.something, so gong for this all the time.
        this->identifier = scope->getNewRandomIdentifier(); // TODO: Fix this shit. Register as some type of object property in scope
        std::cout << "Identifier:::" <<  identifier << "\n";
    }
}

void MemberExpression::print(std::ostream& out) const {
    if (is_identifier) {
        out << "this." << identifier;
    } else {
        out << *expression;
    }
}

std::ostream& operator<<(std::ostream& out, const MemberExpression& e) {
    e.print(out);
    return out;
}
