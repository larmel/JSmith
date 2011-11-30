#include "CallStatement.h"
#include "CallExpression.h"
#include "Expression.h"
#include "Variable.h"

// Must only be used as the last statements in a program
CallStatement::CallStatement(Scope* s, int depth) : Statement(s, depth) {
    expression = new CallExpression(s, 0);
    expression->function->lock();
}

void CallStatement::print(std::ostream& out)
{
    this->printIndentation(out);
    expression->print(out);
    out << ";" << std::endl;
}
