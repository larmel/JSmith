#include "WhileStatement.h"
#include <iostream>
#include "Expression.h"
#include "Variable.h"
#include "Scope.h"
#include "BlockStatement.h"

void WhileStatement::print(std::ostream& out, unsigned int depth){
	
	Expression *e = Expression::generate_expression(this->scope);
	Variable* newvar = scope->generateNewVariable(NUMBER_T);
	for (int t = 0; t < depth; ++t){
		out << "   ";
	}
	out << "while(false)" << std::endl;
	
	int r = rand() % 100;
	Statement* q;
	
	if(r < 50){
		q = new BlockStatement(scope);
		q->print(out, depth);
	}else{
		q = Statement::newRandomStatement(scope);
		q->print(out, depth+1);
	}
}
