#ifndef BLOCK_STATEMENT_H
#define BLOCK_STATEMENT_H

#include "Statement.h"
#include <vector>

class BlockStatement : public Statement {
private:
	std::vector<Statement*> statements;
public:
	BlockStatement(Scope* x);
	void print(std::ostream& out, unsigned int depth);
	
};

#endif