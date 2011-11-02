#include <iostream>
#include <string>
#include "IfStatement.h"
#include "Expression.h"
#include "Statement.h"
#include "BlockStatement.h"
#include "RandomDiscreteDistribution.h"


IfStatement::IfStatement(Scope* s) : Statement(s) {

	expression = Expression::generateExpressionForConditional(this->scope);
    false_statement = NULL;
    true_is_block = false_is_block = false;
	
	// Either a block with new statements, or a one-line if
	RandomDiscreteDistribution rt(2,4,1);
	
	if(rt.getChosenIndex() == 0) {
		true_statement = new BlockStatement(scope);
		true_is_block = true;
	} else {
		true_statement = Statement::newRandomStatement(scope);
	}
	
	RandomDiscreteDistribution rf(2,1,1);
	
	if(rf.getChosenIndex() == 1)
	{
	    RandomDiscreteDistribution r (2,3,1);
	    if(r.getChosenIndex() == 0) {
		    false_statement = new BlockStatement(scope);
		    false_is_block = true;
	    } else {
		    false_statement = Statement::newRandomStatement(scope);
	    }

	}
	
}

void IfStatement::print(std::ostream& out, unsigned int depth){
	std::string prefix = "";
	for (int t = 0; t < depth; ++t){
		prefix += "   ";
	}
	out << prefix << "if (";

	expression->print(out, 1);
	
	out << ")" << std::endl;
	
	// Print block on same depth
	if (true_is_block){
	    depth--;
	}
	
	true_statement->print(out, depth + 1);
	
	if(false_statement != 0){
	    out << prefix << "else" << std::endl;
	    false_statement->print(out, depth + 1);
	}
	
}
