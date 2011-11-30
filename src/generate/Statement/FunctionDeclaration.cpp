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
        this->source_elements.push_back( Statement::newRandomStatement(this, depth ) );
    }

}

/*
 * Creates a new instance variable
 */
void FunctionDeclaration::setParent(Variable *v) {
    v->parent = this->variable;
    this->variable->addProperty(v);
}

void FunctionDeclaration::print(std::ostream& out)
{
    //std::string indent;
    //for (int t = 0; t < depth; ++t) indent += "   ";
    this->printIndentation(out);
    
    out << "function " << this->variable->identifier;
    out << "()" << std::endl;
    this->printIndentation(out);
    out << "{" << std::endl;
    
    for (int i = 0; i < source_elements.size(); ++i) {
        source_elements[i]->print(out);
    }
    this->printIndentation(out);
    out << "}" << std::endl;
}


