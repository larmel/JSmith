#include "FunctionDeclaration.h"
#include "Variable.h"
#include "SourceElement.h"
#include "ReturnStatement.h"
#include "RandomDiscreteDistribution.h"

void FunctionDeclaration::generate() {
    
    // The new class scope
    this->variable = scope->generateClassVariable(0);

    // Create some number of Statements
    // Do not want nested declarations
    for (int i = 0; i < 4; ++i) {
        this->source_elements.push_back( Statement::newRandomStatement(this, depth + 1) );
    }
    
    RandomDiscreteDistribution return_or_not (2, 4, 1);
    
    if(return_or_not.getChosenIndex() == 0){
        this->source_elements.push_back(new ReturnStatement(this, depth));
    }
}

void FunctionDeclaration::setParent(Variable *v) {
    v->parent = this->variable;
}

void FunctionDeclaration::print(std::ostream& out)
{
    std::string indent;
    for (int t = 0; t < depth; ++t) indent += "   ";
    
    out << indent << "function " << this->variable->identifier;
    out << "()" << std::endl << indent << "{" << std::endl;
    
    for (int i = 0; i < source_elements.size(); ++i) {
        source_elements[i]->print(out);
    }
    
    out << indent << "}" << std::endl;
}


