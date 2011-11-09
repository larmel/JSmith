#include "ExpressionStatement.h"
#include "AssignmentExpression.h"
#include "RandomDiscreteDistribution.h"
#include "Expression.h"

ExpressionStatement::ExpressionStatement(Scope* s, unsigned int depth) : Statement(s, depth){
    // Todo alternate between function call and other expressions
    RandomDiscreteDistribution d = RandomDiscreteDistribution(3, 3, 0, 8 );
    
    // TODO: Do this for several types
    Type type = NUMBER_T;

    switch(d.getChosenIndex()){
    case 0:
        expression = new CallExpression(s, 0, type);
        break;
    case 1:
        expression = Expression::generateExpression(s, 0, type);
        break;
    
    case 2:
        expression = new AssignmentExpression(s, 0, type);
        break;
    }
	
}
void ExpressionStatement::print(std::ostream& out)
{
    for (int t = 0; t < depth; ++t) out << "   ";
	expression->print(out);
	out << ";" << std::endl;
}
