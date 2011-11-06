#include "SourceElement.h"
#include "Statement.h"
#include "FunctionDeclaration.h"

#include <cstdlib>

// Limit function count, or we will get segfault
static int function_count = 3;

SourceElement* SourceElement::createRandom(Scope* parent_scope, unsigned int depth)
{
    int flip = rand() % 2;
    if (flip == 0 && function_count-- > 0) 
    {
        return new FunctionDeclaration(parent_scope, depth);
    }
    
	return Statement::newRandomStatement(parent_scope, depth);
}

/*
 * Simply print the correct number of spaces for indentation.
 * Derived classes should call this before other print code. 
 */
std::ostream& operator<<(std::ostream& out, const SourceElement& e) {
    for (int i = 0; i < e.depth; ++i) {
        for (int j = 0; j < e.indentation; ++j) {
            out << " ";
        }
    }
    return out;
}


