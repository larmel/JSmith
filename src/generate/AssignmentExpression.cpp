#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Variable.h"
#include "Literal.h"
#include "Scope.h"


AssignmentExpression::AssignmentExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    // Fetch a random variable
    // TODO: Something else than number here?

	RandomDiscreteDistribution d = RandomDiscreteDistribution(1, 10);
   
    // Switch what type of variable to assign 
    switch(d.getChosenIndex()) {
        case 0:
            this->left_side = parent_scope->getRandomVariable(NUMBER_T);
            this->right_side = Expression::generateExpression(parent_scope);
        break;
    
    }
    
   
    if (this->left_side==NULL) {
        // No variables available, what to do?
    } 
    

}

void AssignmentExpression::print(std::ostream& out, unsigned int depth) {
    if (this->left_side==NULL || this->right_side==NULL) 
    {
        // No left or right side available, what to do?
    } 
    
    else
    {
        out << left_side->name << " = ";
        right_side->print(out, depth);
    }
}
