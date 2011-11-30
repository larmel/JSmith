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

    RandomDiscreteDistribution r(5,
            10,     // a = function() { ... }
            50,     // a = { b: function() { ... }, ... }
            100,    // a = new A();
            100,    // this.a = 42
            150     // a = b + c, default reassign
    );

    switch (r.getChosenIndex()) {
		case 0:
		{
			FunctionExpression* fexpr = new FunctionExpression(scope, depth);
			left_variable = scope->generateFunctionVariable( fexpr->numberOfArguments() );
			right_expression = (Expression*) fexpr;
			break;
		}
        case 1:
        {
            MapExpression* mexpr = new MapExpression(parent_scope, depth);
            left_variable = parent_scope->generateMapVariable( );
            right_expression = (Expression*) mexpr;
            break;
        }
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
			// Generate a new number variable, can be property (this.) if inside FunctionDeclaration
            right_expression = Expression::generateExpression(scope);
			left_variable = scope->generateNumberVariable( Random::flip_coin() || Random::flip_coin() );
			break;
		}
        default:
            // Reassign some existing number variable
            right_expression = Expression::generateExpression(scope);
            left_variable = scope->getRandomNumberVariable();
            break;
    }
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
