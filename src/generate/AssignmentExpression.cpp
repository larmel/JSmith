#include "AssignmentExpression.h"
#include "Variable.h"
#include "Scope.h"


AssignmentExpression::AssignmentExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    // Fetch a random variable
    // TODO: Something else than number here?
    this->left_side = parent_scope->getRandomVariable(NUMBER_T);

    if (this->left_side==NULL) {
        // No functions available, what to do?
    } 
    
    this->right_side = Expression::generateExpression(parent_scope);
}

void AssignmentExpression::print(std::ostream& out) {
    if (this->left_side==NULL) 
    {
        // No variables available, what to do?
    } 
    
    else
    {
        out << left_side->name << " = ";
        right_side->print(out);
    }
}
