#include "Statement.h"
#include "Expression.h"
#include "VariableStatement.h"
#include "IfStatement.h"
#include "BlockStatement.h"

Statement* Statement::newRandomStatement(Scope* x){
	int r = rand() % 2;
	if(r == 0){
		return new VariableStatement(x);
	}else if(r == 1){
		return new IfStatement(x);
	}
	//return new BlockStatement(x);
}
