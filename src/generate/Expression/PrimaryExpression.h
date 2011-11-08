#ifndef PRIMARY_EXPRESSION_H
#define PRIMARY_EXPRESSION_H
 
#include <iostream>
#include <cstdlib>
#include <string>
#include "Expression.h"

class Variable;
class Scope;

/*
 * From ECMA standard
 *
 * PrimaryExpression ->
 *      this
 *      Identifier
 *      Literal
 *      ArrayLiteral
 *      ObjectLiteral
 *      ( Expression )
 *
 * Choose this to be a terminal for now.
 * TODO: Change to allow nesting?
 */
class PrimaryExpression : public Expression {

private:
    Variable *variable;
    bool imm;
    std::string imm_val;
    
public:
    PrimaryExpression(Scope* parent_scope, int depth);
    void print(std::ostream& out) const;
    
    
    friend std::ostream& operator<<(std::ostream& out, const PrimaryExpression& e);
};
 
 
#endif
