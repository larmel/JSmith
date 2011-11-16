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
#include <iostream>
using namespace std;

Statement* Statement::newRandomStatement(Scope* x, int depth){
    
	RandomDiscreteDistribution d = RandomDiscreteDistribution(6, 
	    200, 
	    50, 
	    0, // while is bugged
	    x->getParent() == NULL ? 0 : 10, // Only pick return if we are in a function
	    50, 
	    depth < 3 ? 50 : 0); // Do not nest more than 3 for-loops (performance)
	
	switch(d.getChosenIndex()){
	    case 0:
	        return new VariableStatement(x, depth);
	    case 1:
	        return new IfStatement(x, depth);
	    case 2:
	        return new WhileStatement(x, depth);
	    case 3:
	        return new ReturnStatement(x, depth);
	    case 4:
	        return new ExpressionStatement(x, depth);
        case 5:
	        return new ForStatement(x, depth);
	    default:
	        exit(2);
	}
}
