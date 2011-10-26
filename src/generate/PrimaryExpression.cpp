#include "PrimaryExpression.h"
#include "Variable.h"
#include "Scope.h"
#include <climits>
#include "RandomDiscreteDistribution.h"
#include <sstream>
#include <cstdio>

// PrimaryExpression, terminal node in the expression tree

PrimaryExpression::PrimaryExpression(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    this->imm = false;
   
    RandomDiscreteDistribution r (4, 1, 1, 1, 1);
     
    // Create a immediate
    if (r.getChosenIndex() == 0 || this->scope->getRandomVariable(NUMBER_T) == NULL) 
    {
        this->imm = true;
        std::stringstream sst;
        RandomDiscreteDistribution type_of_immediate (4, 1, 1, 1, 1);
        
        switch(type_of_immediate.getChosenIndex())
        {
            // Int
            case 0:
                sst << rand() % INT_MAX;
                break;
            // Decimal
            case 1:
                sst << rand() % INT_MAX << "." << rand() % INT_MAX;
                break;
            // Hex
            case 2:
            {
                char buffer[30];
                sprintf(buffer, "0x%x", rand() % INT_MAX);
                sst << buffer;
                break;
            }
           // Compex normal form decimal
           case 3:
            {
                sst << rand() % 10 << "." << rand() % INT_MAX << rand() % INT_MAX << "E" << rand() % 309;
                break;
            }    
        }

        this->imm_val = sst.str();
    }
    // Get an already existing variable
    else 
    {
        this->variable = this->scope->getRandomVariable(NUMBER_T);
    }
}

void PrimaryExpression::print(std::ostream& out) {
    // Print variable or immediate
    if (this->imm) {
        out << imm_val;
    } else {
        out << variable->name;
    }
}
