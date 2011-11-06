#include "BlockStatement.h"
#include <iostream>
#include <vector>

BlockStatement::BlockStatement(Scope* s, unsigned int depth) : Statement(s, depth) {
	const int maxBlockStatements = 2;
	for (int i = 0; i < maxBlockStatements; i++) {
	    statements.push_back( Statement::newRandomStatement(scope, depth) );
	}
}

void BlockStatement::print(std::ostream& out)
{
	for (int t = 0; t < depth; ++t){ 
		out << "   ";
	}
	out << "{" << std::endl;
	
	for (int i = 0; i < statements.size(); ++i) {
		statements.at(i)->print(out);
	}
	
	for (int t = 0; t < depth; ++t){
		out << "   ";
	}
	out <<  "}" << std::endl;
}