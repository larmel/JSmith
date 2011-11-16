#include "FunctionDeclaration.h"
#include "Variable.h"
#include "SourceElement.h"
#include "ReturnStatement.h"
#include "RandomDiscreteDistribution.h"

void FunctionDeclaration::generate() {
    this->variable = new ClassVariable(0);
    
    // Create some number of SourceElements
    // Might want to enforce some return type
    for (int i = 0; i < 8; ++i) {
        this->source_elements.push_back( SourceElement::createRandom(this, depth) );
    }
    
    RandomDiscreteDistribution return_or_not (2, 4, 1);
    
    if(return_or_not.getChosenIndex() == 0){
        this->source_elements.push_back(new ReturnStatement(this, depth));
    }
}

void FunctionDeclaration::print(std::ostream& out)
{
    std::string indent;
    for (int t = 0; t < depth; ++t) indent += "   ";
    
    out << indent << "function " << *this->variable << "()" << std::endl << indent << "{" << std::endl;
    
    for (int i = 0; i < source_elements.size(); ++i) {
        source_elements[i]->print(out);
    }
    
    out << indent << "}" << std::endl;
}


