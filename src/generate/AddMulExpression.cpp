#include "AddMulExpression.h"
#include "Variable.h"

AddMulExpression::AddMulExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    
    // Get variables to work on:
    // TODO: Other types than NUMBER_T aswell?

    this->op1 = Expression::generateExpression(this->scope, this->depth+1);
    this->op2 = Expression::generateExpression(this->scope, this->depth+1);
    if (this->op1==NULL) 
        std::cerr << "No operator 1\n";   
    if (this->op1==NULL) 
        std::cerr << "No operator 2\n";
    
    // Pick the operator 
    int op_id = rand() % 4;
    switch (op_id) {
    case 0: this->op = "+"; break;
    case 1: this->op = "-"; break;
    case 2: this->op = "*"; break;
    case 3: this->op = "/"; break;
    }
}

void AddMulExpression::print(std::ostream& out, unsigned int depth) {
    // Print variable
    op1->print(out, depth);
    out << this->op;
    op2->print(out, depth);
}
