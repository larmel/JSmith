#ifndef BLOCK_STATEMENT_H
#define BLOCK_STATEMENT_H

#include <vector>
#include "Statement.h"

class BlockStatement : public Statement {
private:
    std::vector<Statement*> statements;

public:
    BlockStatement(Scope* s, int depth);
    void print(std::ostream& out);
};

#endif
