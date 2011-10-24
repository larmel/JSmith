#include "RelationalExpression.h"
#include "Variable.h"
#include "Scope.h"


RelationalExpression::RelationalExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    
    this->op1 = Expression::generate_expression(this->scope, this->depth+1);
    this->op2 = Expression::generate_expression(this->scope, this->depth+1);

    // Pick the operator 
    int op_id = rand() % 4;
    switch (op_id) {
    case 0: this->op = "<"; break;
    case 1: this->op = ">"; break;
    case 2: this->op = "<="; break;
    case 3: this->op = ">="; break;
    }
    
}

void RelationalExpression::print(std::ostream& out, unsigned int depth) {
    op1->print(out, depth);
    out << this->op;
    op2->print(out, depth);
}
