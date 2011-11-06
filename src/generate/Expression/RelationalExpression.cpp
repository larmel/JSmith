#include "RelationalExpression.h"
#include "Variable.h"
#include "Scope.h"


RelationalExpression::RelationalExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    
    this->op1 = Expression::generateExpression(this->scope, this->depth+1);
    this->op2 = Expression::generateExpression(this->scope, this->depth+1);

    // Pick the operator 
    int op_id = rand() % 4;
    switch (op_id) {
    case 0: this->op = " < "; break;
    case 1: this->op = " > " ; break;
    case 2: this->op = " <= "; break;
    case 3: this->op = " >= "; break;
    }
    
}

void RelationalExpression::print(std::ostream& out) const {
    op1->print(out);
    out << this->op;
    op2->print(out);
}

std::ostream& operator<<(std::ostream& out, const RelationalExpression& e) {
    e.print(out);
    return out;
}

