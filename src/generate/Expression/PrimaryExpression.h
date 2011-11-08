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
 * Use static factory method to generate any of the three first.
 * An instance if PrimaryExpression will always be 'this'
 * TODO: Change to allow nesting?
 */
class PrimaryExpression : public Expression {

private:
    std::string immidiate_value;

public:
    PrimaryExpression(Scope* parent_scope, int depth);
    
    static Expression* generatePrimaryExpression(Scope* scope, int depth);

    virtual void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const PrimaryExpression& e);
};
 
 
#endif
