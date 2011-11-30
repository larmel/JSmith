#include "ForStatement.h"
#include "Expression.h"
#include "Variable.h"
#include "Scope.h"
#include "BlockStatement.h"
#include "Random.h"
#include "RandomDiscreteDistribution.h"
#include <iostream>

ForStatement::ForStatement(Scope* scope, unsigned int parent_depth) : Statement(scope, parent_depth) 
{
    this->loop_guard = scope->generateNumberVariable(false);
    loop_guard->lock();
    
    this->expr_b = Expression::generateExpressionForConditional(scope);
    this->expr_c = Expression::generateExpression(scope);

    Scope* s = new Scope(scope);
    is_block = false;
    RandomDiscreteDistribution r (2, 3, 1);
	if (r.getChosenIndex() == 0) {
		statement = new BlockStatement(s, depth-1);
		is_block = true;
	} else {
		statement = Statement::newRandomStatement(s, depth);
	}
	
	loop_guard->unlock();
}

void ForStatement::print(std::ostream& out)
{
	this->printIndentation(out);
	out << "for (var " << loop_guard->identifier << " = 0; (" << *expr_b << ") && "<< loop_guard->identifier << "++ < ";
	out << Random::randint(0,30);
	out << "; " << *expr_c << ")" << std::endl;
	statement->print(out);
}
