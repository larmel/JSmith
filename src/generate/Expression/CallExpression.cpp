#include "CallExpression.h"
#include "Variable.h"
#include "Scope.h"


CallExpression::CallExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    // Fetch a local function (we're only allowed to call functions on the same level)
    this->function = parent_scope->getRandomFunctionVariable();

    // TODO Create expressions to use as args
}

void CallExpression::print(std::ostream& out) const {
    if (this->function == NULL)
    {
        // No functions available, what to do?
        out << "1";
    } 
    
    else
    {
        out << *this->function << "()"; // TODO args
    }
}


std::ostream& operator<<(std::ostream& out, const CallExpression& e) {
    e.print(out);
    return out;
}

