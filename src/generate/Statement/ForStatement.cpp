#include "ForStatement.h"
#include "Expression.h"
#include "Variable.h"
#include "Scope.h"
#include "BlockStatement.h"
#include "Random.h"
#include <iostream>

ForStatement::ForStatement(Scope* scope, unsigned int parent_depth) : Statement(scope, parent_depth) 
{
    this->loop_guard = scope->generateNumberVariable();
    loop_guard->lock();
    
    this->expr_b = Expression::generateExpressionForConditional(scope);
    this->expr_c = Expression::generateExpression(scope);
    
    is_block = false;
	if (Random::flip_coin()) {
		statement = new BlockStatement(scope, depth-1);
		is_block = true;
	} else {
		statement = Statement::newRandomStatement(scope, depth); 
	}
	
	loop_guard->unlock();
}

void ForStatement::print(std::ostream& out)
{
	this->printIndentation(out);
	out << "for (var " << loop_guard->identifier << " = 0; (" << *expr_b << ") && "<< loop_guard->identifier << "++ < 42;" << *expr_c << ")" << std::endl;
	statement->print(out);
}
