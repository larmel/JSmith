#ifndef CALL_EXPRESSION_H
#define CALL_EXPRESSION_H
 
#include <iostream>
#include <cstdlib>

#include "Expression.h"
#include "Type.h"

class Variable;
class Scope;
 
class CallExpression : public Expression {

private:
    Variable *function;
    

public:
    CallExpression(Scope* parent_scope, int depth, Type type);
    
    void print(std::ostream& out) const;
    
    friend std::ostream& operator<<(std::ostream& out, const CallExpression& e);
};
 
 
 #endif
