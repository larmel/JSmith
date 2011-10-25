#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

class Scope;

class Expression {
private:	
    Scope* scope; 
    std::vector<Expression*> expressions;
	
public:
    Expression(Scope *parent_scope);
    
    static Expression *generate_expression(Scope *scope);
    
	virtual void print(std::ostream& out, unsigned int depth);
	
	
	
};

#endif
