#include "BlockStatement.h"
#include "Random.h"
#include <iostream>
#include <algorithm>
#include <vector>

BlockStatement::BlockStatement(Scope* s, int depth) : Statement(s, depth) {

    // Decreasing number of statements as depth increases
	int n_stmt = Random::randint(1, std::max(10 - depth, 1));

	for (int i = 0; i < n_stmt; i++) {
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
