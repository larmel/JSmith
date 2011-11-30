#include <iostream>
#include <string>
#include "IfStatement.h"
#include "Scope.h"
#include "Expression.h"
#include "Statement.h"
#include "BlockStatement.h"
#include "RandomDiscreteDistribution.h"


IfStatement::IfStatement(Scope* s, int depth) : Statement(s, depth) {

	expression = Expression::generateExpressionForConditional(this->scope);
    false_statement = NULL;
    true_is_block = false_is_block = false;
	
	// Either a block with new statements, or a one-line if
	RandomDiscreteDistribution rt(2,4,1);

    Scope* s_true = new Scope(scope);
	if(rt.getChosenIndex() == 0) {
		true_statement = new BlockStatement(s_true, depth);
		true_is_block = true;
	} else {
		true_statement = Statement::newRandomStatement(s_true, depth + 1);
	}
	
	RandomDiscreteDistribution rf(2,1,1);
	
	if (rf.getChosenIndex() == 1)
	{
	    RandomDiscreteDistribution r(2,3,1);

	    Scope* s_false = new Scope(scope);
	    if (r.getChosenIndex() == 0) {
		    false_statement = new BlockStatement(s_false, depth );
		    false_is_block = true;
	    } else {
		    false_statement = Statement::newRandomStatement(s_false, depth + 1);
	    }
	}
}

void IfStatement::print(std::ostream& out) {
	this->printIndentation(out);
	out << "if (";
	expression->print(out);
	out << ")" << std::endl;
	
	true_statement->print(out);
	
	if(false_statement != 0) {
		this->printIndentation(out);
	    out << "else" << std::endl;
	    false_statement->print(out);
	}
}
