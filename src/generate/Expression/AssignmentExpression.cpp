#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "FunctionExpression.h"
#include "MapExpression.h"
#include "Random.h"
#include "Variable.h"
#include "Literal.h"
#include "Scope.h"

AssignmentExpression::AssignmentExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    left_variable = NULL;
    right_variable = NULL;
    right_expression = NULL;

    // TODO:
    // Reassign number variables
    // Object properies, this.... ??? Handled already, by virtual setParent
    // new FunctionDeclaration
    // Assign to MapExpression

    RandomDiscreteDistribution r(5, 10, 10, 20, 15, 10);

    switch (r.getChosenIndex()) {
		case 0:
		{
			FunctionExpression* fexpr = new FunctionExpression(scope, depth);
			left_variable = scope->generateFunctionVariable( fexpr->numberOfArguments() );
			right_expression = (Expression*) fexpr;
			break;
		}
		case 1:
			// Reassign some existing number variable
			left_variable = scope->getRandomNumberVariable();
			right_expression = Expression::generateExpression(scope);
			break;
		case 2:
		{
			// Create new instance of FunctionDeclaration
			ClassVariable* classVariable = scope->getRandomClassVariable();

			if (classVariable != NULL) {
				// Add all object properties as instance variables
				left_variable = scope->generateObjectVariable();
				right_variable = (ClassVariable*) classVariable;
				scope->createInstance(classVariable, left_variable);
				break;
			}
		}
		case 3:
		{
			MapExpression* mexpr = new MapExpression(parent_scope, depth);
			left_variable = parent_scope->generateMapVariable( );
			right_expression = (Expression*) mexpr;
			break;
		}
		default:
		{
			// Generate a new number variable, can be property if inside FunctionDeclaration
			left_variable = scope->generateNumberVariable( Random::flip_coin() );
			right_expression = Expression::generateExpression(scope);
			break;
		}
    }

    // Create object with new keyword
    /*if (false) {
        left_variable = scope->generateNewVariable(OBJECT_T);
        right_variable = scope->getRandomVariable(FUNCTION_T);
        if (right_variable != NULL) {
            // Add all instance variables to scope
            std::vector<Variable*>* properties = right_variable->getObjectProperties();
            for (int i = 0; i < properties->size(); ++i) {
                Variable* property = properties->at(i);
                Variable* added_property = new Variable(property->name, property->type);
                added_property->is_property = true;
                added_property->attachedObject = right_variable;
                scope->add(added_property);
            }
        }

    } else {*/


/*

	RandomDiscreteDistribution d = RandomDiscreteDistribution(2, 0, 10);
	this->left_variable = NULL;
	Variable* function = NULL;

	switch (d.getChosenIndex()) {
	case 0:
		// Assign to some existing variable. Fall through if none is found.
		left_variable = scope->generateNumberVariable();
		if (left_variable != NULL) {
			right_expression = Expression::generateExpression(parent_scope, depth + 1);
			break;
		}
	case 1:
		// Generate new property for this object
		right_expression = Expression::generateExpression(parent_scope, depth + 1);
		left_variable = new NumberVariable();
		break;
	}



*/

    //}
}

void AssignmentExpression::print(std::ostream& out) const {
    if (right_variable != NULL) {
        out << *left_variable << " = new " << right_variable->identifier << "()"; // TODO: Arguments
    } else {
        out << *left_variable << " = " << *right_expression;
    }
}

std::ostream& operator<<(std::ostream& out, const AssignmentExpression& e) {
    e.print(out);
    return out;
}

