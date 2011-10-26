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


Statement* Statement::newRandomStatement(Scope* x){

	RandomDiscreteDistribution d = RandomDiscreteDistribution(6, 200, 50, 50, x->getParent() == NULL ? 0 : 10, 50, 50);
	
	switch(d.getChosenIndex()){
	    case 0:
	        return new VariableStatement(x);
	    case 1:
	        return new IfStatement(x);
	    case 2:
	        return new WhileStatement(x);
	    case 3:
	        return new ReturnStatement(x);
	    case 4:
	        return new ExpressionStatement(x);
        case 5:
	        return new ForStatement(x);
	    default:
	        exit(2);
	
	}
	
}
