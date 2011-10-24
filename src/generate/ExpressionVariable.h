#ifndef EXPRESSIONVARIABLE_H
#define EXPRESSIONVARIABLE_H 
 
#include <iostream>
#include "Variable.h"
#include "Function.h"
#include "Expression.h"
#include <cstdlib>
 
class ExpressionVariable : public Expression {

private:
    // TODO: Something else than NUMBER_T
    Variable *variable;
    Function *parent;
public:
    ExpressionVariable(Function *parent);
    
    void print(std::iostream& out);

};
 
 
 #endif
