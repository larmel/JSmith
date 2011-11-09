#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Variable.h"
#include "Literal.h"
#include "Scope.h"

AssignmentExpression::AssignmentExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

	RandomDiscreteDistribution d = RandomDiscreteDistribution(2, 1, 1);
	this->left_variable = NULL;

    switch (d.getChosenIndex()) {
    case 0:
        // Assign to some existing variable. Fall through if none is found.
        left_variable = scope->getRandomVariable(NUMBER_T); // TODO type
        if (left_variable != NULL) {
            right_expression = Expression::generateExpression(parent_scope);
            break;
        }
    case 1:
        // Generate new property for this object
        Variable* property = scope->generateNewProperty(NUMBER_T);
        left_variable = property;
        right_expression = Expression::generateExpression(parent_scope, depth + 1);
        break;
    case 2:
        // Create new object. Not implemented yet
        left_variable = scope->generateNewVariable(OBJECT_T);
        right_expression = Expression::generateExpression(scope, depth + 1, OBJECT_T);
        break;
    }

}

void AssignmentExpression::print(std::ostream& out) const {
    out << *left_variable << " = " << *right_expression;
}

std::ostream& operator<<(std::ostream& out, const AssignmentExpression& e) {
    e.print(out);
    return out;
}

