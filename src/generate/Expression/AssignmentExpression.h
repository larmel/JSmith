#ifndef ASSIGNMENT_EXPRESSION_H
#define ASSIGNMENT_EXPRESSION_H
 
#include <iostream>
#include <cstdlib>
#include "Expression.h"
#include "Type.h"

class MemberExpression;
class LeftHandSideExpression;
class Variable;
class Scope;
 
/*
 * AssignmentExpression ->
 *      ConditionalExpression
 *      LeftHandSideExpression '=' AssignmentExpression
 *      LeftHandSideExpression AssignmentOperator AssignmentExpression
 *
 * We always choose the second production, ie always have an equals sign.
 * The right hand side is simplified to ConditionalExpression, which again can be
 * reduced to (almost) any expression.
 *
 * LeftHandSideExpression ->
 *      NewExpression ->
 *          MemberExpression
 *          new NewExpression
 *      CallExpression
 *
 */
class AssignmentExpression : public Expression {

private:
    Type type;

    Variable* left_variable;
    Variable* right_variable;

    Expression* right_expression;
    
public:
    AssignmentExpression(Scope* parent_scope, int depth, Type type);
    
    void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const AssignmentExpression& e);
};

#endif
