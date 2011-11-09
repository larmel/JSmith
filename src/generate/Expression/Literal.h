#ifndef LITERAL_H
#define LITERAL_H 
 
#include <iostream>
#include <cstdlib>
#include <string>
#include "Expression.h"

#include "Type.h"
class Variable;
class Scope;

enum LiteralType {
    L_NULL, L_BOOLEAN, L_NUMERIC, L_STRING/*, L_REGULAR_EXPRESSION*/
};

/*
 * From ECMA standard
 *
 * Literal ->
 *      NullLiteral
 *      BooleanLiteral
 *      NumericLiteral
 *      StringLiteral
 *      RegularExpressionLiteral
 *
 * Terminal node for strings and numbers
 * TODO: Fix, this class is not used everywhere, but it should
 */
class Literal : public Expression {

private:
    std::string literal_val;
    std::string randomNumericLiteral();
    std::string randomStringLiteral();
    
public:
    Literal(Scope* parent_scope, int depth, Type type);
    LiteralType type;

    void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const Literal& e);
};

#endif 
