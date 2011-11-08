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
    static Expression *generateExpression(Scope *scope, int depth = 0);
    static Expression *generateExpressionForConditional(Scope *scope, int depth = 0);
	
	virtual void print(std::ostream& out) const;
	
    /*
     * Only here for convenience. Still need the virtual print function
     * for dynamic method dispatch.
     */
    friend std::ostream& operator<<(std::ostream& out, const Expression& e);
};

#endif
