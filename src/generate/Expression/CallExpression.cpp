#include "CallExpression.h"
#include "Variable.h"
#include "Scope.h"


CallExpression::CallExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    // Fetch a local function (we're only allowed to call functions on the same level)
    this->function = parent_scope->getRandomFunctionVariable();
    for(int i = 0; i < this->function->getNumArguments(); i++){
    	this->parameters.push_back(Expression::generateExpression(parent_scope, depth));
    }

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
        out << *this->function << "(";
        for(int i = 0; i < this->function->getNumArguments(); i++){
        	out << *this->parameters.at(i);
        	if(i !=this->function->getNumArguments()){
				out << ", ";
        	}
        }
        out << ")";
    }
}


std::ostream& operator<<(std::ostream& out, const CallExpression& e) {
    e.print(out);
    return out;
}

