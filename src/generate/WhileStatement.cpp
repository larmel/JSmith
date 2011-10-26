#include "WhileStatement.h"
#include "Expression.h"
#include "Variable.h"
#include "Scope.h"
#include "BlockStatement.h"
#include "Random.h"
#include <iostream>

WhileStatement::WhileStatement(Scope* scope, unsigned int depth) : Statement(scope, depth) {

    // TODO: Generate some complicated loop expression
	//Expression *e = Expression::generate_expression(this->scope);
	//Variable* newvar = scope->generateNewVariable(NUMBER_T);
    
    is_block = false;
    
	if (Random::flip_coin()) {
		statement = new BlockStatement(scope, depth + 1);
		is_block = true;
	} else {
		statement = Statement::newRandomStatement(scope, depth + 1); 
	}
}


void WhileStatement::print(std::ostream& out, unsigned int depth){
	
	for (int t = 0; t < depth; ++t){
		out << "   ";
	}
	out << "while (false)" << std::endl;
	
	// Don't increase print depth for block
	if (is_block) depth--;
	
	statement->print(out, depth + 1);
}
