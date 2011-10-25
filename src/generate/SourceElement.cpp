#include "SourceElement.h"
#include "Statement.h"
#include "FunctionDeclaration.h"

#include <cstdlib>

// Limit function count, or we will get segfault
static int function_count = 3;

SourceElement* SourceElement::createRandom(Scope* parent_scope)
{
    int flip = rand() % 2;
    if (flip == 0 && function_count-- > 0) 
        return new FunctionDeclaration(parent_scope);
    
	return Statement::newRandomStatement(parent_scope);
}
