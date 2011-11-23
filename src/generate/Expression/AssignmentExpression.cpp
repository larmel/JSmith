#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "FunctionExpression.h"
#include "Random.h"
#include "Variable.h"
#include "Literal.h"
#include "Scope.h"

AssignmentExpression::AssignmentExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    left_variable = NULL;
    right_variable = NULL;
    right_expression = NULL;

    RandomDiscreteDistribution r(4,
            10,     // a = function() { ... }
            10,     // a = b + c
            100,    // a = new A();
            100     // this.a = 42
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
    default:
        {
            // Generate a new number variable, can be property if inside FunctionDeclaration
            left_variable = scope->generateNumberVariable( Random::flip_coin() );
            right_expression = Expression::generateExpression(scope);
            break;
        }
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

