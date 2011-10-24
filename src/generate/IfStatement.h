#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include "Statement.h"

class Expression;
class Statement;

class IfStatement : public Statement {
private:
    Expression* expression;
    Statement* statement;
    bool is_block;

public:
	IfStatement(Scope* s);
	void print(std::ostream& out, unsigned int depth);
};

#endif
