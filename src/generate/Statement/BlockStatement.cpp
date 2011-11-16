#include "BlockStatement.h"
#include <iostream>
#include <vector>

BlockStatement::BlockStatement(Scope* s, unsigned int depth) : Statement(s, depth) {
	const int maxBlockStatements = 2;
	for (int i = 0; i < maxBlockStatements; i++) {
	    statements.push_back( Statement::newRandomStatement(scope, depth+1) );
	}
}

void BlockStatement::print(std::ostream& out)
{

	this->printIndentation(out);

	out << "{" << std::endl;
	
	for (int i = 0; i < statements.size(); ++i) {
		statements.at(i)->print(out);
	}
	
	this->printIndentation(out);

	out <<  "}" << std::endl;
}
