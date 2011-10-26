#ifndef FOR_STATEMENT_H
#define FOR_STATEMENT_H

#include "Statement.h"

class Expression;
class Statement;
class Variable;

class ForStatement : public Statement {
private:
    Variable* loop_guard;
    Expression* expr_b;
    Expression* expr_c;
    Statement* statement;
    bool is_block;
    
public:
	ForStatement(Scope* s, unsigned int depth);
	void print(std::ostream& out, unsigned int depth);
};

#endif

