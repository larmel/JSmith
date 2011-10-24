#ifndef WHILE_STATEMENT_H
#define WHILE_STATEMENT_H

#include "Statement.h"

class Expression;
class Statement;

class WhileStatement : public Statement {
private:
    Expression* expression;
    Statement* statement;
    bool is_block;
    
public:
	WhileStatement(Scope* s);
	void print(std::ostream& out, unsigned int depth);
};

#endif
