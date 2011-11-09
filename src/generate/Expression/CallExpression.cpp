#include "CallExpression.h"
#include "Variable.h"
#include "Scope.h"


CallExpression::CallExpression(Scope* parent_scope, int depth, Type type) : Expression(parent_scope, depth, type) {

    // Fetch a local function (we're only allowed to call functions on the same level)
    this->function = parent_scope->getRandomLocalVariable(FUNCTION_T);

    if (this->function!=NULL) {
        this->function->funcBeenUsed = true;
    } // No functions available, what to do?
}

void CallExpression::print(std::ostream& out) const {
    if (this->function==NULL) 
    {
        // No functions available, what to do?
        //out << "NOFUNC()";
    } 
    
    else
    {
        out << this->function->name << "()";
    }
}


std::ostream& operator<<(std::ostream& out, const CallExpression& e) {
    e.print(out);
    return out;
}

