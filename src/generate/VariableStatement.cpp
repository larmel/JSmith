#include "VariableStatement.h"
#include <iostream>
#include "Variable.h"
#include "Scope.h"
#include "Expression.h"

void VariableStatement::print(std::ostream& out, unsigned int depth){
	Variable* newvar = scope->generateNewVariable(NUMBER_T);
	for (int t = 0; t < depth; ++t) out << "   ";
	out << "var ";
	out << newvar->name;
	out << " = ";
	
	Expression *e = Expression::generate_expression(this->scope);
	e->print(out, 1);
	
	out << ";" << std::endl;
	
	delete e;
}
