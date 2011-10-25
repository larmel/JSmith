#include "Expression.h"

#include "PrimaryExpression.h"
#include "AddMulExpression.h"
#include "RelationalExpression.h"
//TODO: Create subclasses to instantiate instead

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

Expression *Expression::generate_expression(Scope *scope, int depth) {


    int gen_type = rand() % 100;
    
    // TODO: So far this only creates 1 new expression, not utilizing the list
    // Using several should work though.
    
    Expression *expression = new Expression(scope, depth);
    

    // Linear increasing probability for terminal expression nodes
    int p_terminal = 50 + 50*((double)depth/10);

    if (gen_type < p_terminal) // Generate a terminal node (PrimaryExpression)
    {
        // PrimaryExpression (actual variables)
        Expression *subexpr = new PrimaryExpression(scope, depth);
        expression->expressions.push_back(subexpr);
        
    } 
    
    
    else  // Generate some sort of non-terminal node:
    {
        gen_type = rand() % 100;
        
        if (gen_type<70) // Generate a AddMulExpression
        {
            Expression *subexpr = new AddMulExpression(scope, depth);
            expression->expressions.push_back(subexpr);
        }
        
        else if (gen_type < 90) // Generate <,>,>=,<= Expression
        {
            Expression *subexpr = new RelationalExpression(scope, depth);
            expression->expressions.push_back(subexpr);
        
        }
        
        else if (gen_type < 100) // Generate '(' Expression ')'
        {
            Expression *subexpr = Expression::generate_expression(scope, depth+1);
            expression->expressions.push_back(subexpr);
            
            expression->parenthesis = true;
        }
        
    }
    

    return expression;
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

