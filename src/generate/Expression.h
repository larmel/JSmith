#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

class Scope;

class Expression {
private: 
    std::vector<Expression*> expressions;
    
protected:
    Scope* scope;
    int depth;
    bool parenthesis;
	
public:
    Expression(Scope *parent_scope, int depth);
    
    static Expression *generate_expression(Scope *scope, int depth = 0);
    
	virtual void print(std::ostream& out, unsigned int depth);
	
	
	
};

#endif
