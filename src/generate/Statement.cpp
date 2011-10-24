#include "Statement.h"
#include "Expression.h"
#include "VariableStatement.h"
#include "IfStatement.h"
#include "WhileStatement.h"


Statement* Statement::newRandomStatement(Scope* x){
	int r = rand() % 10;
	if(r > 1){
		return new VariableStatement(x);
	}else if (r == 1) {
		return new IfStatement(x);
	}else if (r == 0) {
		return new WhileStatement(x);
	}
}
