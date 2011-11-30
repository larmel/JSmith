#ifndef CALL_EXPRESSION_H
#define CALL_EXPRESSION_H
 
#include <iostream>
#include <cstdlib>

#include "Expression.h"

class FunctionVariable;
class Scope;
 
class CallExpression : public Expression {

private:
    std::vector<Expression*> parameters;

public:
    FunctionVariable *function;
    CallExpression(Scope* parent_scope, int depth);
    
    void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const CallExpression& e);
};
 
 
 #endif
