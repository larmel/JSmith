#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include "Statement.h"

class IfStatement : public Statement {
	
public:
	IfStatement(Scope* x) : Statement(x) {}
	void print(std::ostream& out, unsigned int depth);
	
};

#endif