#include <iostream>

#include "VariableStatement.h"
#include "Variable.h"
#include "RandomDiscreteDistribution.h"
#include "Literal.h"
#include "Scope.h"
#include "Expression.h"


VariableStatement::VariableStatement(Scope* s, unsigned int depth) : Statement(s, depth) {
    
    // Generate expression first to avoid circle dependency
	RandomDiscreteDistribution d = RandomDiscreteDistribution(2, 10, 5);
	
	switch (d.getChosenIndex()) {
	case 0:
        this->expression = Expression::generateExpression( scope, 0, NUMBER_T );
        this->var = scope->generateNewVariable(NUMBER_T);
    break;
    
    case 1:
        this->expression = new Literal(scope, depth, STRING_T);
        this->var = scope->generateNewVariable(STRING_T);
    break;
    }
    line_end = ";";        
}

void VariableStatement::print(std::ostream& out){
	
	for (int t = 0; t < depth; ++t) out << "   ";
	out << "var " << var->name << " = ";
	expression->print(out);
	out << line_end << std::endl;
}
