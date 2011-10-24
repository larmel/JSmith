#ifndef VARIABLE_STATEMENT_H
#define VARIABLE_STATEMENT_H

#include "Statement.h"

class VariableStatement : public Statement {
	
public:
	VariableStatement(Scope* x) : Statement(x) {}
	void print(std::ostream& out, unsigned int depth);
	
};

#endif