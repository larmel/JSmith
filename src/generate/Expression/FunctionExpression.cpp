#include "FunctionExpression.h"
#include "Variable.h"
#include "Scope.h"
#include "Statement.h"
#include "RandomDiscreteDistribution.h"
#include "ReturnStatement.h"

FunctionExpression::FunctionExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    this->depth = depth;
    Scope *scope = new Scope(parent_scope);
    scope->allowReturn = true;
    scope->is_function_expression = true;

    // Add formal parameters to scope
    int num_args = rand() % 4;
    for (int i = 0; i < num_args; i++) {
        arguments.push_back(scope->generateNumberVariable());
    }

    // Create some number of Statements. Not SourceElements, as we do not want FunctionDeclaration
    for (int i = 0; i < 2; ++i) {
        this->statements.push_back( Statement::newRandomStatement(scope, depth) );
    }

    RandomDiscreteDistribution return_or_not (2, 50, 1);
    if(return_or_not.getChosenIndex() == 0){
        this->statements.push_back(new ReturnStatement(scope, depth));
    }
}

int FunctionExpression::numberOfArguments() {
    return arguments.size();
}

void FunctionExpression::print(std::ostream& out) const {

    out << "function (";
    for (int i = 0; i < arguments.size(); i++) {
        out << *arguments.at(i);
        if(i != arguments.size() -1){
            out << ", ";
        }
    }
    out << ") {" << std::endl;
    for (int i = 0; i < statements.size(); ++i) {
        statements[i]->print(out);
    }
    // Fake indentation
    for (int i = 0; i < depth-1; ++i) {
        out << "    ";
    }
    out <<  "}";
}

std::ostream& operator<<(std::ostream& out, const FunctionExpression& e) {
    e.print(out);
    return out;
}
