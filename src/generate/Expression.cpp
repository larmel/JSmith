#include "Expression.h"

#include "ExpressionVariable.h"
//TODO: Create subclasses to instantiate instead

Expression::Expression(Scope *scope) 
{
    if (scope==NULL) {
        std::cerr << "No scope provided to Expression node";
        exit(1);
    }
    
    this->scope = scope;
}

Expression *Expression::generate_expression(Scope *scope) {
        
    int gen_type = rand() % 1;
    
    Expression *expression = new Expression(scope);

    
    switch (gen_type) {
    case 0:
    {
        // EqualityExpression
        Expression *subexpr = new ExpressionVariable(scope);
        if (subexpr==NULL) {
            std::cerr << "No expressionvariable returned";
            exit(1);
        }
        expression->expressions.push_back(subexpr);
        
    break;
    }
    }
    
    
    return expression;
}
    

void Expression::print(std::ostream &out, unsigned int depth)
{
    // TODO: 
    for (int i = 0; i<this->expressions.size(); i++) {
        this->expressions[i]->print(out, 1);
        if (i<this->expressions.size()-1) {
            out << ",";        
        }
    }
}

