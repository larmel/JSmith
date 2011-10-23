#ifndef EXPRESSIONVARIABLE_H
#define EXPRESSIONVARIABLE_H 
 
#include <iostream>
#include "Variable.h"
#include "function.h"
#include "expression.h"
#include <cstdlib>
 
class ExpressionVariable : public Expression {

private:
    // TODO: Interface variable class (does not compile)
    Variable variable;
    Function *parent;
public:
    ExpressionVariable(Function *parent);
    
    void print(std::iostream& out);

};
 
 
 #endif
