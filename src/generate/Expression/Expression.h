#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Type.h"
class Scope;


class Expression {
private: 
    std::vector<Expression*> expressions;
    
protected:
    Scope* scope;
    int depth;
    Type type;
    bool parenthesis;
	
public:
    // TODO: Remove the default types when done with expressions
    Expression(Scope *parent_scope, int depth, Type type = NUMBER_T);
    static Expression *generateExpression(Scope *scope, int depth = 0, Type type = NUMBER_T);
    static Expression *generateExpressionForConditional(Scope *scope, int depth = 0, Type type = NUMBER_T);
	
	virtual void print(std::ostream& out) const;
	
    /*
     * Only here for convenience. Still need the virtual print function
     * for dynamic method dispatch.
     */
    friend std::ostream& operator<<(std::ostream& out, const Expression& e);
};

#endif
