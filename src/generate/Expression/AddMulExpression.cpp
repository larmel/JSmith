#include "AddMulExpression.h"
#include "Variable.h"

#include <string>

AddMulExpression::AddMulExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    
    op1 = Expression::generateExpression(scope, depth + 1);
    op2 = Expression::generateExpression(scope, depth + 1);
    
    std::string operand[] = {"+", "-", "*", "/", "%"};
    op = operand[rand() % 5];
}

void AddMulExpression::print(std::ostream& out) const {
    op1->print(out);
    out << this->op;
    op2->print(out);
}

std::ostream& operator<<(std::ostream& out, const AddMulExpression& e) {
    e.print(out);
    return out;
}
