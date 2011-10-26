#ifndef EXPRESSION_STATEMENT_H
#define EXPRESSION_STATEMENT_H
#include "Statement.h"
#include "Expression.h"
#include "CallExpression.h"
 
class ExpressionStatement : public Statement {
private:
 	Expression* expression;
public:
	ExpressionStatement(Scope*);
	void print(std::ostream&, unsigned int);
};
 #endif
