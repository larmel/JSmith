#include <iostream>
#include <string>
#include "IfStatement.h"
#include "Expression.h"
#include "Statement.h"
#include "BlockStatement.h"
#include "RandomDiscreteDistribution.h"


IfStatement::IfStatement(Scope* s, unsigned int depth) : Statement(s, depth) {

	expression = Expression::generateExpressionForConditional(this->scope);
    false_statement = NULL;
    true_is_block = false_is_block = false;
	
	// Either a block with new statements, or a one-line if
	RandomDiscreteDistribution rt(2,4,1);
	
	if(rt.getChosenIndex() == 0) {
		true_statement = new BlockStatement(scope, depth);
		true_is_block = true;
	} else {
		true_statement = Statement::newRandomStatement(scope, depth + 1);
	}
	
	RandomDiscreteDistribution rf(2,1,1);
	
	if(rf.getChosenIndex() == 1)
	{
	    RandomDiscreteDistribution r (2,3,1);
	    if(r.getChosenIndex() == 0) {
		    false_statement = new BlockStatement(scope, depth );
		    false_is_block = true;
	    } else {
		    false_statement = Statement::newRandomStatement(scope, depth + 1);
	    }

	}
	
}

void IfStatement::print(std::ostream& out){
	std::string prefix = "";
	for (int t = 0; t < depth; ++t){
		prefix += "   ";
	}
	out << prefix << "if (";

	expression->print(out);
	
	out << ")" << std::endl;
	
	// Print block on same depth
	/*if (true_is_block){
	    depth--;
	}*/
	
	true_statement->print(out);
	
	/*if(true_is_block){
	    depth++;
	}*/
	
	if(false_statement != 0){
	    //depth++;
	    out << prefix << "else" << std::endl;
	    /*if(false_is_block){
	        depth--;
	    }*/
	    false_statement->print(out);
	}
	
}
