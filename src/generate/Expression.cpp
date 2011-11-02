#include "Expression.h"

#include "PrimaryExpression.h"
#include "AddMulExpression.h"
#include "RelationalExpression.h"
#include "CallExpression.h"
#include "RandomDiscreteDistribution.h"

Expression::Expression(Scope *scope, int depth) 
{
    if (scope==NULL) {
        std::cerr << "No scope provided to Expression node";
        exit(1);
    }
    
    this->scope = scope;
    this->depth = depth;
    this->parenthesis = false;
}

Expression *Expression::generateExpression(Scope *scope, int depth) {

    int gen_type = rand() % 100;
    
    // TODO: So far this only creates 1 new expression, not utilizing the list
    // Using several should work though.
    
    Expression *expression = new Expression(scope, depth);

    // Linear increasing probability for terminal expression nodes
    int p_terminal = 40 + 60*((double)depth/20);

    if (gen_type < p_terminal) // Generate a terminal node (PrimaryExpression)
    {
        // PrimaryExpression (actual variables)
        Expression *subexpr = new PrimaryExpression(scope, depth);
        expression->expressions.push_back(subexpr);
        
    } 
    
    
    else  // Generate some sort of non-terminal node:
    {

		RandomDiscreteDistribution r (3, 40, 10, 1);
		Expression *subexpr;
		
		switch(r.getChosenIndex())
		{
			case 0:
				subexpr = new AddMulExpression(scope, depth);
				expression->expressions.push_back(subexpr);
				break;
			case 1:
				subexpr = Expression::generateExpression(scope, depth+1);
				expression->expressions.push_back(subexpr);
				expression->parenthesis = true;
				break;
			case 2:
				subexpr = new RelationalExpression(scope, depth);
				expression->expressions.push_back(subexpr);
				break;
			
		}

    }
    
    return expression;
}
    

Expression *Expression::generateExpressionForConditional(Scope *scope, int depth) {
	RandomDiscreteDistribution r (2, 90, 10);
	if(r.getChosenIndex() == 0){
	    return new RelationalExpression(scope, depth);
	}else{
	    return Expression::generateExpression(scope, depth);
	}

}
    
    
    
    
// Print function
void Expression::print(std::ostream &out, unsigned int depth)
{
    if (this->parenthesis) out << "(";
    
    for (int i = 0; i<this->expressions.size(); i++) {
        this->expressions[i]->print(out, 1);
        if (i<this->expressions.size()-1) {
            out << ",";        
        }
    }
    
    if (this->parenthesis) out << ")";
    
}

