#include "WhileStatement.h"
#include "Expression.h"
#include "Variable.h"
#include "Scope.h"
#include "BlockStatement.h"
#include "../RandomDiscreteDistribution.h"
#include "../Random.h"
#include <iostream>

WhileStatement::WhileStatement(Scope* parent_scope, int parent_depth) : Statement(parent_scope, parent_depth)
{
    this->loop_guard = parent_scope->generateNumberVariable(false);
    loop_guard->lock();
    this->expression = Expression::generateExpressionForConditional(parent_scope);

    Scope* new_scope = new Scope(parent_scope);

    RandomDiscreteDistribution rw(2,6,1);

	if (rw.getChosenIndex() == 0) {
		statement = new BlockStatement(new_scope, parent_depth+1);
	} else {
		statement = Statement::newRandomStatement(new_scope, parent_depth+2);
	}
	loop_guard->unlock();
}

void WhileStatement::print(std::ostream& out) 
{
	this->printIndentation(out);
	out << "{" << std::endl;
	this->printIndentation(out);
	out << "    var " << loop_guard->identifier << " = 0, A = 1;" << std::endl;
	this->printIndentation(out);
	out << "    while ( (";
	expression->print(out);
	out << ") && A == 1 && " << loop_guard->identifier << "++ < ";
	out << Random::randint(0,200);
	out << ")" << std::endl;
	statement->print(out);
	this->printIndentation(out);
	out << "}" << std::endl;
}
