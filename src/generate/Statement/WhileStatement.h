#ifndef WHILE_STATEMENT_H
#define WHILE_STATEMENT_H

#include "Statement.h"

class Expression;
class Statement;
class Variable;

class WhileStatement : public Statement {
private:
    Variable* loop_guard;
    Expression* expression;
    Statement* statement;
    bool is_block;
    
public:
	WhileStatement(Scope* s, int depth);
	void print(std::ostream& out);
};

#endif
