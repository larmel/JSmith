#include "CallExpression.h"
#include "Variable.h"
#include "Scope.h"
#include <iostream>
#include <cassert>

CallExpression::CallExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    this->function = parent_scope->getRandomFunctionVariable();

    // Caller should make sure a function exists in scope
    assert(function != NULL);

    for(int i = 0; i < this->function->getNumArguments(); i++){
        this->parameters.push_back(Expression::generateExpression(parent_scope, depth));
    }
}

void CallExpression::print(std::ostream& out) const {
    out << *this->function << "(";
    for(int i = 0; i < this->function->getNumArguments(); i++){
        out << *this->parameters.at(i);
        if(i != this->function->getNumArguments() - 1){
            out << ", ";
        }
    }
    out << ")";
}

std::ostream& operator<<(std::ostream& out, const CallExpression& e) {
    e.print(out);
    return out;
}
