#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Variable.h"
#include "Literal.h"
#include "Scope.h"

AssignmentExpression::AssignmentExpression(Scope* parent_scope, int depth, Type type) : Expression(parent_scope, depth, type) {

    // Create object with new keyword
    if (type & OBJECT_T) {
        left_variable = scope->generateNewVariable(OBJECT_T);
        new_keyword = " new ";
        right_expression = Expression::generateExpression(scope, depth + 1, OBJECT_T);

    } else {

        RandomDiscreteDistribution d = RandomDiscreteDistribution(2, 1, 10);
        this->left_variable = NULL;
        this->new_keyword = "";

        switch (d.getChosenIndex()) {
        case 0:
            // Assign to some existing variable. Fall through if none is found.
            left_variable = scope->getRandomVariable(type); // TODO type
            if (left_variable != NULL) {
                right_expression = Expression::generateExpression(parent_scope, depth + 1, type);
                break;
            }
        case 1:
            // Generate new property for this object
            right_expression = Expression::generateExpression(parent_scope, depth + 1, type);
            left_variable = scope->generateNewProperty(type); // Avoid self-reference
            break;
        }
    }
}

void AssignmentExpression::print(std::ostream& out) const {
    out << *left_variable << " = " << new_keyword << *right_expression;
}

std::ostream& operator<<(std::ostream& out, const AssignmentExpression& e) {
    e.print(out);
    return out;
}

