#include "ExpressionStatement.h"
#include "RandomDiscreteDistribution.h"
#include "Expression.h"

ExpressionStatement::ExpressionStatement(Scope* s) : Statement(s){
    // Todo alternate between function call and other expressions
    RandomDiscreteDistribution d = RandomDiscreteDistribution(2, 4, 1 );
    
    switch(d.getChosenIndex()){
    case 0:
        expression = new CallExpression(s, 0);
        break;
    case 1:
        expression = Expression::generateExpression(s);
        break;
    }
	
}
void ExpressionStatement::print(std::ostream& out, unsigned int depth)
{
    for (int t = 0; t < depth; ++t) out << "   ";
	expression->print(out, depth);
	out << ";" << std::endl;
}
