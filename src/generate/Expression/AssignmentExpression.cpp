#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Variable.h"
#include "Literal.h"
#include "Scope.h"

AssignmentExpression::AssignmentExpression(Scope* parent_scope, int depth, Type type) : Expression(parent_scope, depth, type) {

    this->type = type;

    // Create object with new keyword
    if (type & OBJECT_T) {
        left_variable = scope->generateNewVariable(OBJECT_T);
        right_variable = scope->getRandomVariable(FUNCTION_T);

        // Add all instance variables to scope
        std::vector<Variable*>* properties = right_variable->getObjectProperties();
        for (int i = 0; i < properties->size(); ++i) {
            Variable* property = properties->at(i);
            Variable* added_property = new Variable(property->name, property->type);
            added_property->is_property = true;
            added_property->attachedObject = right_variable;
            scope->add(added_property);
        }

    } else {

        RandomDiscreteDistribution d = RandomDiscreteDistribution(2, 1, 10);
        this->left_variable = NULL;

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
    if (type & OBJECT_T)
        out << *left_variable << " = new " << *right_variable;
    else
        out << *left_variable << " = " << *right_expression;
}

std::ostream& operator<<(std::ostream& out, const AssignmentExpression& e) {
    e.print(out);
    return out;
}

