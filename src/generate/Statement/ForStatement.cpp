#include "ForStatement.h"
#include "Expression.h"
#include "Variable.h"
#include "Scope.h"
#include "BlockStatement.h"
#include "Random.h"
#include <iostream>

ForStatement::ForStatement(Scope* scope, unsigned int parent_depth) : Statement(scope, parent_depth) 
{
    this->loop_guard = scope->generateNewVariable( NUMBER_T );
    loop_guard->lock();
    
    this->expr_b = Expression::generateExpression(scope);
    this->expr_c = Expression::generateExpression(scope);
    
    is_block = false;
	if (Random::flip_coin()) {
		statement = new BlockStatement(scope, depth);
		is_block = true;
	} else {
		statement = Statement::newRandomStatement(scope, depth); 
	}
	
	loop_guard->unlock();
}

void ForStatement::print(std::ostream& out)
{
	// TODO: Make indentation be a property of SourceElement
	/*for (int t = 0; t < depth; ++t) out << "   ";
	out << "for (var " << loop_guard->name << " = 0; (" << expr_b << ") && "<< loop_guard->name << "++ < 42;" << expr_c << ")" << endl;
	out << statement*/
	
	out << *this;
	out << "for (var " << loop_guard->name << " = 0; (" << *expr_b << ") && "<< loop_guard->name << "++ < 42;" << *expr_c << ")" << std::endl;
	/*
	out << "for (var " << loop_guard->name << " = 0;";
	out << "("; 
	    expr_b->print(out); 
	out << ") && " << loop_guard->name << "++ < 42;";
	    expr_c->print(out); 
	out << ")" << std::endl;*/
	
	statement->print(out);
}