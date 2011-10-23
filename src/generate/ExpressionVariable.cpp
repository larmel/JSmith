#include "ExpressionVariable.h"
 
// CLASS EXPRESSIONVARIABLE


ExpressionVariable::ExpressionVariable(Function *parent) {
    this->parent = parent;
    
    this->variable = Variable.getRandomLocal(NUMBER_T);
    
    if (this->variable==NULL) {
        // Die if there is no variable returned
        std::cerr << "ExpressionVariable.cpp did not get a variable";
        std::exit(1);
    }

}
    
void ExpressionVariable::print(std::iostream& out) {
    
    this->variable.print(out);

}
