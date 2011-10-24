#include "ExpressionVariable.h"
#include "Variable.h"

ExpressionVariable::ExpressionVariable(Scope* parent_scope) : Expression(parent_scope) {
    
    this->variable = new Variable(NUMBER_T);
//    this->variable = Variable.getRandomLocal(NUMBER_T);
    
    if (this->variable==NULL) {
        // Die if there is no variable returned
        std::cerr << "ExpressionVariable.cpp did not get a variable";
        std::exit(1);
    }
}

void ExpressionVariable::print(std::ostream& out, unsigned int depth) {
    out << "Expression var" << std::endl;
//    this->variable.print(out);

}
