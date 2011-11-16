#include "WhileStatement.h"
#include <Expression.h>
#include <Variable.h>
#include "Scope.h"
#include "BlockStatement.h"
#include "Random.h"
#include <iostream>

WhileStatement::WhileStatement(Scope* scope, int parent_depth) : Statement(scope, parent_depth) 
{
    this->loop_guard = scope->generateNumberVariable();
    loop_guard->lock();
    
    this->expression = Expression::generateExpression(scope);

    is_block = Random::flip_coin();
	if (is_block) {
		statement = new BlockStatement(scope, depth);
	} else {
		statement = Statement::newRandomStatement(scope, depth); 
	}
	
	loop_guard->unlock();
}

void WhileStatement::print(std::ostream& out) 
{	
	for (int t = 0; t < depth; ++t){
		out << "   ";
	}
	out << "var " << loop_guard->identifier << " = 0, ";
	out << "while ( (";
	expression->print(out);
	out << ") && " << loop_guard->identifier << "++ < 42 )" << std::endl;
	
	statement->print(out);
}
