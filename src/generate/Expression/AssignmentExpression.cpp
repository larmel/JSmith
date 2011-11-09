#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Variable.h"
#include "Literal.h"
#include "Scope.h"
#include "MemberExpression.h"

AssignmentExpression::AssignmentExpression(Scope* parent_scope, int depth, Type type) : Expression(parent_scope, depth, type) {

	RandomDiscreteDistribution d = RandomDiscreteDistribution(2, 1, 1);
	this->left_variable = NULL;
	this->left_expression = NULL;

    // Switch what type of variable to assign 
    switch(d.getChosenIndex()) {
    case 0:
        // TODO: Either move lots of logic up here, or make MemberExpression handle decision of everything
        this->left_variable = parent_scope->getRandomVariable(NUMBER_T);
        if (this->left_variable != NULL) {
            this->right_side = Expression::generateExpression(parent_scope);
            break;
        }
    case 1:
        this->left_expression = new MemberExpression(scope, depth);
        this->right_side = Expression::generateExpression(parent_scope);
        break;
    }

    /*
     * TODO: MemberExpressio
     * Want to cover:
     * - some_var = expression
     * - this.property = expression
     *   - this.property = function() { ... }
     * - some_var = new ...
     */
}

void AssignmentExpression::print(std::ostream& out) const {
    if (left_variable != NULL) {
        out << left_variable->name << " = " << *right_side;
    } else {
        out << *left_expression << " = " << *right_side;
    }
}

std::ostream& operator<<(std::ostream& out, const AssignmentExpression& e) {
    e.print(out);
    return out;
}

