#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "FunctionExpression.h"
#include "Variable.h"
#include "Literal.h"
#include "Scope.h"

AssignmentExpression::AssignmentExpression(Scope* scope, int depth) : Expression(scope, depth) {

    RandomDiscreteDistribution r(2, 10, 0);

    // Create function expression
    if (r.getChosenIndex()==0) {
        FunctionExpression* fexpr = new FunctionExpression(scope, depth);
        left_variable = scope->generateFunctionVariable( fexpr->numberOfArguments() );
        right_expression = (Expression*) fexpr;
    }


    else if (r.getChosenIndex()==1) {

        //scope->generateObjece

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
    if (false) {
        out << *left_variable << " = new ";
        if (right_variable == NULL)
            out << "Object";
        else
            out << *right_variable << "()";
    } else {
        out << *left_variable << " = " << *right_expression;
    }
}

std::ostream& operator<<(std::ostream& out, const AssignmentExpression& e) {
    e.print(out);
    return out;
}

