#include "ForStatement.h"
#include "Expression.h"
#include "Variable.h"
#include "Scope.h"
#include "BlockStatement.h"
#include "Random.h"
#include <iostream>

ForStatement::ForStatement(Scope* scope) : Statement(scope) 
{
    this->loop_var = scope->generateNewVariable( NUMBER_T );
    loop_var->lock();
    
    is_block = false;
	if (Random::flip_coin()) {
		statement = new BlockStatement(scope);
		is_block = true;
	} else {
		statement = Statement::newRandomStatement(scope); 
	}
	
	loop_var->unlock();
}

void ForStatement::print(std::ostream& out, unsigned int depth){
	
	for (int t = 0; t < depth; ++t){
		out << "   ";
	}
	out << "for (var " << loop_var->name << " = 0; " << loop_var->name << " < 10; " << loop_var->name << "++)" << std::endl;
	
	// Don't increase print depth for block
	if (is_block) depth--;
	
	statement->print(out, depth + 1);
}
