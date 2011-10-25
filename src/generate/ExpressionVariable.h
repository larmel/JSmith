#ifndef EXPRESSION_VARIABLE_H
#define EXPRESSION_VARIABLE_H 
 
#include <iostream>
#include <cstdlib>

#include "Expression.h"

class Variable;
class Scope;
 
class ExpressionVariable : public Expression {

private:
    Variable *variable;
    
public:
    ExpressionVariable(Scope* parent_scope);
    
    void print(std::ostream& out, unsigned int depth);
};
 
 
 #endif
