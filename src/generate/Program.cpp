#include "Program.h"
#include "SourceElement.h"
#include "Variable.h"
#include "VariableStatement.h"
#include <vector>
#include <string>

Program::Program() : Scope(NULL) {

    for (int i = 0; i < 8; i++) {
        this->source_elements.push_back( new VariableStatement(this,0));
    }

    // Generate some number (currently 3) of SourceElements
    for (int i = 0; i < 3; ++i) {
	    this->source_elements.push_back( SourceElement::createRandom(this, 0) );
	}

	// TODO: Generate code for main function instead of just printing?
}

void Program::print(std::ostream& out) 
{
    for (int i = 0; i < this->source_elements.size(); ++i) {
	    this->source_elements.at(i)->print(out);
	}
	printMain(out);
}

void Program::printMain(std::ostream& out)
{
    out << "" << std::endl << "(function () {" << std::endl;
    
    std::vector<Variable*>::iterator it;
    
    /*
    // Call all functions in global scope
    for (it = this->variables->begin(); it != this->variables->end(); ++it) {
        Variable* var = *it;
        if (var->getType() == FUNCTION_T)
        {
            // For now assuming object is a zero argument function
            out << "   " << *var << "();" << std::endl;
        }
    }
    */
    
    // Print all variables in global scope
    int line = 0;
    for (it = this->variables->begin(); it != this->variables->end(); ++it) {
        Variable* var = *it;
        if (var->getType() == NUMBER_T || var->getType() == STRING_T)
        {
            line++;
            out << "   " << "print(" << *var << "); print(\" (" << line << ") \");" << std::endl;
        }
    }
    
    out << "})();" << std::endl;
}	

