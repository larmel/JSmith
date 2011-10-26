#include "CallExpression.h"
#include "Variable.h"
#include "Scope.h"


CallExpression::CallExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    // Fetch a local function (we're only allowed to call functions on the same level)
    this->function = parent_scope->getRandomLocalVariable(FUNCTION_T);

    if (this->function==NULL) {
        // No functions available, what to do?
    }
    
}

void CallExpression::print(std::ostream& out, unsigned int depth) {
    for (int t = 0; t < depth; ++t){ 
	    out << "   ";
    }
	
    if (this->function==NULL) 
    {
        out << ";"; // No functions available, what to do?
    } 
    
    else
    {
        out << this->function->name << "()";
    }
    out << std::endl;
}
