#ifndef ADDMULEXPRESSION_H
#define ADDMULEXPRESSION_H 
 
#include <iostream>
#include <cstdlib>

#include "Expression.h"

class Variable;
class Scope;

// Class for addition, subtraction, multiplication and division
// in expressions.
 
class AddMulExpression : public Expression {

private:
    // Operands:
    Expression *op1;
    Expression *op2;
    
    // Operator:
    std::string op;
    
public:

    AddMulExpression(Scope* parent_scope, int depth);
    
    void print(std::ostream& out) const;
    
    friend std::ostream& operator<<(std::ostream& out, const AddMulExpression& e);
};
 
 
 #endif
