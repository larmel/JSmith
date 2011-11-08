#ifndef ASSIGNMENT_EXPRESSION_H
#define ASSIGNMENT_EXPRESSION_H
 
#include <iostream>
#include <cstdlib>
#include "Expression.h"

class Variable;
class Scope;
 
/*
 * From ECMA standard
 *
 * AssignmentExpression ->
 *      ConditionalExpression
 *      LeftHandSideExpression '=' AssignmentExpression
 *      LeftHandSideExpression AssignmentOperator AssignmentExpression
 *
 * We always choose the second production.
 * The right hand side is simplified to ConditionalExpression, which again can be
 * reduced to LeftHandSideExpression(!) = (almost) any expression.
 */
class AssignmentExpression : public Expression {

private:
    Variable *left_side;
    Expression *right_side;
    
public:
    AssignmentExpression(Scope* parent_scope, int depth);
    
    void print(std::ostream& out) const;
    
    friend std::ostream& operator<<(std::ostream& out, const AssignmentExpression& e);
};

#endif
