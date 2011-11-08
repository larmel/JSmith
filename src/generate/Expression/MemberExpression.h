#ifndef MEMBER_EXPRESSION
#define MEMBER_EXPRESSION

#include "Expression.h"
#include <iostream>
#include <string>

class Scope;
class Variable;

/*
 * MemberExpression ->
 *      PrimaryExpression (*)
 *      FunctionExpression (*)
 *      MemberExpression [ Expression ]
 *      MemberExpression . IdentifierName (*)
 *      new MemberExpression Arguments
 */
class MemberExpression : public Expression {
private:
    Expression* expression;
    std::string identifier;
    bool is_primary;
    bool is_function;
    bool is_identifier;

public:
    MemberExpression(Scope* scope, int depth);

    void print(std::ostream& out) const;
    friend std::ostream& operator<<(std::ostream& out, const MemberExpression& e);
};

#endif
