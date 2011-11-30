#include "Statement.h"
#include "Expression.h"
#include "VariableStatement.h"
#include "IfStatement.h"
#include "WhileStatement.h"
#include "ForStatement.h"
#include "ExpressionStatement.h"
#include "ReturnStatement.h"
#include "Scope.h"
#include "RandomDiscreteDistribution.h"

Statement* Statement::newRandomStatement(Scope* x, int depth){
    
	RandomDiscreteDistribution d = RandomDiscreteDistribution(6,
        250, // Expression statement
		120, // Variable statement
		30,  // if, else
        x->allowReturn ? 10 : 0, // Only pick return if we are in a function
        depth < 3 ? 20 : 0,  // while ...
		depth < 3 ? 30 : 0); // for ... Do not nest more than 3 loops (termination)

	switch(d.getChosenIndex()) {
        case 0:
            return new ExpressionStatement(x, depth);
		case 1:
			return new VariableStatement(x, depth);
		case 2:
			return new IfStatement(x, depth);
        case 3:
            return new ReturnStatement(x, depth);
        case 4:
            return new WhileStatement(x, depth);
		case 5:
			return new ForStatement(x, depth);
		default:
			exit(2);
	}
}
