#include "FunctionDeclaration.h"
#include "Variable.h"
#include "SourceElement.h"
#include "ReturnStatement.h"
#include "RandomDiscreteDistribution.h"

void FunctionDeclaration::generate() {
    this->identifier = generateNewVariable( FUNCTION_T );
    
    // TODO: Argument list
    
    // Create some number of SourceElements
    // Might want to enforce some return type
    for (int i = 0; i < 10; ++i) {
        this->source_elements.push_back( SourceElement::createRandom(this) );
    }
    
    RandomDiscreteDistribution return_or_not (2, 4, 1);
    
    if(return_or_not.getChosenIndex() == 0){
        this->source_elements.push_back(new ReturnStatement(this));
    }
}

void FunctionDeclaration::print(std::ostream& out, unsigned int depth)
{
    std::string indent;
    for (int t = 0; t < depth; ++t) indent += "   ";
    
    out << indent << "function " << this->identifier->name << "()" << std::endl << indent << "{" << std::endl;
    
    for (int i = 0; i < source_elements.size(); ++i) {
        source_elements[i]->print(out, depth + 1);
    }
    
    out << indent << "}" << std::endl;
}


