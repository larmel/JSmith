#ifndef RELATIONALEXPRESSION_H
#define RELATIONALEXPRESSION_H 
 
#include <iostream>
#include <cstdlib>

#include "Type.h"
#include "Expression.h"


class Variable;
class Scope;
 
class RelationalExpression : public Expression {

private:
    Expression *op1;
    Expression *op2;
    
    std::string op;

public:
    RelationalExpression(Scope* parent_scope, int depth);
    
    void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const RelationalExpression& e);
};
 
 
 #endif
