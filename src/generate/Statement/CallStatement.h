#ifndef CALL_STATEMENT_H
#define CALL_STATEMENT_H

#include "Statement.h"
#include "CallExpression.h"

class CallExpression;

class CallStatement : public Statement {
private:
    CallExpression* expression;

public:
    CallStatement(Scope*, int depth);
    void print(std::ostream&);
};
 #endif
