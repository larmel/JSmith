#ifndef PRIMARYEXPRESSION_H
#define PRIMARYEXPRESSION_H 
 
#include <iostream>
#include <cstdlib>

#include "Expression.h"

class Variable;
class Scope;
 
class PrimaryExpression : public Expression {

private:
    Variable *variable;
    
public:
    PrimaryExpression(Scope* parent_scope);
    
    void print(std::ostream& out, unsigned int depth);
};
 
 
 #endif
