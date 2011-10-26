#ifndef BLOCK_STATEMENT_H
#define BLOCK_STATEMENT_H

#include <vector>
#include "Statement.h"
#include "Expression.h"

class ReturnStatement : public Statement {
private:
    Expression* expression;

public:
    ReturnStatement(Scope* s, unsigned int depth);
    void print(std::ostream& out, unsigned int depth);
};

#endif
