#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <cstdlib>
#include <iostream>

class Scope;

class Expression {
private:	
    Scope* scope;
	
public:
    Expression() { };
    Expression(Scope *parent_scope) : scope(parent_scope) { };
    
	// Pure virtual, abstract class
	virtual void print(std::ostream& out, unsigned int depth) = 0;
};

#endif
