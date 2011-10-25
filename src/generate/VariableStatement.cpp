#include "VariableStatement.h"
#include <iostream>

void VariableStatement::print(std::ostream& out, unsigned int depth){
	
	for (int t = 0; t < depth; ++t) out << "   ";
	out << "var x = 20" << std::endl;
}