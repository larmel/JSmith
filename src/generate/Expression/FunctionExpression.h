#ifndef FUNCTION_EXPRESSION_H
#define FUNCTION_EXPRESSION_H
 
#include <iostream>
#include <cstdlib>
#include <vector>
#include "Expression.h"

class FunctionVariable;
class NumberVariable;
class Statement;
class CallExpression;

class Scope;
 
class FunctionExpression : public Expression {
private:
	std::vector<NumberVariable*> arguments;
	std::vector<Statement*> statements;

	FunctionVariable* function;
public:
    FunctionExpression(Scope* parent_scope, int depth);
    void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const CallExpression& e);
};
 
 
 #endif
