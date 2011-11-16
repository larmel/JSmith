#include "SourceElement.h"
#include "Statement.h"
#include "FunctionDeclaration.h"

#include <cstdlib>

// XXX: Limit function count, or we will get segfault. EDIT: Why segfault?
static int function_count = 3;

SourceElement* SourceElement::createRandom(Scope* parent_scope, unsigned int depth)
{
	// Probability of a new function (sourceelement)
    int flip = rand() % 8;
    if (flip == 0 && function_count-- > 0) 
    {
        return new FunctionDeclaration(parent_scope, depth);
    }
    
    // No function, just create a random statement
	return Statement::newRandomStatement(parent_scope, depth);
}

/*
 * Simply print the correct number of spaces for indentation.
 * Derived classes should call this before other print code. 
 */
void SourceElement::printIndentation(std::ostream& out) {
    for (int i = 0; i < this->depth - 1; ++i) {
        for (int j = 0; j < this->indentation; ++j) {
            out << " ";
        }
    }
}
