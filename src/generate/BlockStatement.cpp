#include "BlockStatement.h"
#include <iostream>
#include <vector>

BlockStatement::BlockStatement(Scope* x) : Statement(x){
	int maxBlockStatements = 3;
	//for(int i = 0; i < maxBlockStatements; i
}

void BlockStatement::print(std::ostream& out, unsigned int depth){

	for (int t = 0; t < depth; ++t){ 
		out << "   ";
	}
	
	out << "{" << std::endl;
	
	for (int i = 0; i < statements.size(); ++i) {
		statements.at(i)->print(out, depth+1);
	}
	
	out << std::endl;
	
	for (int t = 0; t < depth; ++t){
		out << "   ";
	}
	
	out <<  "}" << std::endl;
	
}
