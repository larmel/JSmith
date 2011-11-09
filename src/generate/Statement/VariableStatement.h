#ifndef VARIABLE_STATEMENT_H
#define VARIABLE_STATEMENT_H

#include "Statement.h"

class Variable;
class Expression;

class VariableStatement : public Statement {
private:
    Variable* var;
    Expression* expression;
    std::string line_end;
    
public:
	VariableStatement(Scope* s, int depth);
	void print(std::ostream& out);
};

#endif
