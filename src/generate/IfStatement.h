#ifndef IF_STATEMENT_H
#define IF_STATEMENT_H

#include "Statement.h"

class Expression;
class Statement;

class IfStatement : public Statement {
private:
    Expression* expression;
    Statement* true_statement;
    Statement* false_statement;
    bool true_is_block;
    bool false_is_block;

public:
	IfStatement(Scope* s, unsigned int depth);
	void print(std::ostream& out, unsigned int depth);
};

#endif
