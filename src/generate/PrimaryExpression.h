#ifndef PRIMARYEXPRESSION_H
#define PRIMARYEXPRESSION_H 
 
#include <iostream>
#include <cstdlib>
#include <string>
#include "Expression.h"

// PrimaryExpression, terminal node in the expression tree

class Variable;
class Scope;
 
class PrimaryExpression : public Expression {

private:
    Variable *variable;
    bool imm;
    std::string imm_val;
    
public:
    PrimaryExpression(Scope* parent_scope, int depth);
    void print(std::ostream& out) const;
    
    
    friend std::ostream& operator<<(std::ostream& out, const PrimaryExpression& e);
};
 
 
#endif
