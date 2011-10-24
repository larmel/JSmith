#ifndef WHILE_STATEMENT_H
#define WHILE_STATEMENT_H

#include "Statement.h"

class WhileStatement : public Statement {
	
public:
	WhileStatement(Scope* x) : Statement(x) {}
	void print(std::ostream& out, unsigned int depth);
	
};

#endif
