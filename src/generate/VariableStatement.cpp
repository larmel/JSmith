#include <iostream>

#include "VariableStatement.h"
#include "Variable.h"
#include "Scope.h"
#include "Expression.h"


VariableStatement::VariableStatement(Scope* s) : Statement(s) {
    
    // Generate expression first to avoid circle dependency
    this->expression = Expression::generate_expression( scope );
    this->var = scope->generateNewVariable(NUMBER_T);
    
    int endline = rand() % 2;
    line_end = (endline == 0) ? ";" : "";
        
}

void VariableStatement::print(std::ostream& out, unsigned int depth){
	
	for (int t = 0; t < depth; ++t) out << "   ";
	out << "var " << var->name << " = ";
	expression->print(out, 1);
	out << line_end << std::endl;
}