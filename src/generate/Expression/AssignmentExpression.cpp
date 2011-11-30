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
            100 - 10*depth,     // a = function() { ... }
            (depth == 1) ? 130 : 0,     // a = { b: function() { ... }, ... } Hack: only allow maps in outer scope
            100,    // a = new A();
            100,    // this.a = 42, create variable or property
            150     // a = b + c, default reassign
    );

    switch (r.getChosenIndex()) {
		case 0:
		{
            // Need to generate variable first to reserve identifier. Lock variable in expression.
            FunctionVariable* f_var = scope->generateFunctionVariable( /*fexpr->numberOfArguments()*/ );

            f_var->lock();
			FunctionExpression* fexpr = new FunctionExpression(scope, depth);
			f_var->unlock();

			f_var->setNumArguments( fexpr->numberOfArguments() );

			left_variable = (Variable*) f_var;
			right_expression = (Expression*) fexpr;
			break;
		}
        case 1:
        {
            // Need to generate variable first to reserve identifier. Lock variable in expression.
        	left_variable = parent_scope->generateMapVariable();
        	left_variable->lock();

            MapExpression* mexpr = new MapExpression(parent_scope, depth, left_variable);
            right_expression = (Expression*) mexpr;
            left_variable->unlock();
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
            left_variable = scope->generateNumberVariable( Random::flip_coin() || Random::flip_coin() );
            left_variable->lock();

			// Generate a new number variable, can be property (this.) if inside FunctionDeclaration
            right_expression = Expression::generateExpression(scope);

            left_variable->unlock();
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
