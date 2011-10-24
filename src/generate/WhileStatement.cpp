#include "WhileStatement.h"
#include <iostream>
#include "Expression.h"
#include "Variable.h"
#include "Scope.h"
#include "BlockStatement.h"

WhileStatement::WhileStatement(Scope* s) : Statement(s) {

    // TODO: Generate some complicated loop expression
	//Expression *e = Expression::generate_expression(this->scope);
	//Variable* newvar = scope->generateNewVariable(NUMBER_T);
    
    is_block = false;
    
	int r = rand() % 100;
	if (r < 50) {
		statement = new BlockStatement(scope);
		is_block = true;
	} else {
		statement = Statement::newRandomStatement(scope); 
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
