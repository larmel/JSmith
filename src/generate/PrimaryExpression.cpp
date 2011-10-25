#include "PrimaryExpression.h"
#include "Variable.h"
#include "Scope.h"

// PrimaryExpression, terminal node in the expression tree

PrimaryExpression::PrimaryExpression(Scope* parent_scope) : Expression(parent_scope) {
    this->imm = false;
    

    int gen_type = rand() % 100;    
    if (gen_type<50) { // Create a immediate
     
        // TODO: Need better random immediates!
        this->imm = true;
        this->imm_val = rand();
    }
    
    else if (gen_type<100) // Get an already existing variable
    {
        this->variable = this->scope->getRandomVariable(NUMBER_T);
        if (this->variable==NULL) { // No variable available (generate immediate instead)
            this->imm = true;
            this->imm_val = rand();
        }
    }
}

void PrimaryExpression::print(std::ostream& out, unsigned int depth) {
    // Print variable or immediate
    if (this->imm) {
        out << imm_val;
    } else {
        out << variable->name;
    }
    out << "|" << this->depth << "|";
}
