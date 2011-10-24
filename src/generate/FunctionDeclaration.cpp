#include "FunctionDeclaration.h"
#include "Variable.h"
#include "SourceElement.h"

void FunctionDeclaration::generate() {
    this->identifier = this->getNewRandomIdentifier();
    
    // TODO: Argument list
    
    // Create some number of SourceElements
    // Might want to enforce some return type
    for (int i = 0; i < 4; ++i) {
        this->source_elements.push_back( SourceElement::createRandom(this) );
    }
}

void FunctionDeclaration::print(std::ostream& out, unsigned int depth)
{
    std::string indent;
    for (int t = 0; t < depth; ++t) indent += "   ";
    
    out << indent << "function " << this->identifier << "() {" << std::endl;
    
    for (int i = 0; i < source_elements.size(); ++i) {
        source_elements[i]->print(out, depth + 1);
    }
    
    out << indent << "}" << std::endl;
}


