#include <iostream>
#include "VariableStatement.h"
#include "Variable.h"
#include "RandomDiscreteDistribution.h"
#include "FunctionExpression.h"
#include "Literal.h"
#include "Scope.h"
#include "Expression.h"

VariableStatement::VariableStatement(Scope* s, int depth) : Statement(s, depth) {
    
    // Generate expression first to avoid circle dependency
	RandomDiscreteDistribution d = RandomDiscreteDistribution(2, 10, 0);
	
	switch (d.getChosenIndex()) {
	case 0:
        this->expression = Expression::generateExpression(scope, depth+1);
        this->var = scope->generateNumberVariable(false);
        break;
    }
	RandomDiscreteDistribution use_semicolon = RandomDiscreteDistribution(2, 2, 1);
	if(use_semicolon.getChosenIndex() == 0){
		line_end = ";";
	}
	else
	{
		line_end = "";
	}
}

void VariableStatement::print(std::ostream& out) {
	this->printIndentation(out);
	out << "var " << *var << " = ";
	expression->print(out);
	out << line_end << std::endl;
}
