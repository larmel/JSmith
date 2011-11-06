#ifndef CALLEXPRESSION_H
#define CALLEXPRESSION_H 
 
#include <iostream>
#include <cstdlib>

#include "Expression.h"


class Variable;
class Scope;
 
class CallExpression : public Expression {

private:
    Variable *function;
    

public:
    CallExpression(Scope* parent_scope, int depth);
    
    void print(std::ostream& out) const;
    
    friend std::ostream& operator<<(std::ostream& out, const CallExpression& e);
};
 
 
 #endif
