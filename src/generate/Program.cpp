#include "Program.h"
#include "SourceElement.h"
#include "Variable.h"

#include <vector>

Program::Program() : Scope(NULL) {

    // Generate some number of SourceElements
    for (int i = 0; i < 5; ++i) {
	    this->source_elements.push_back( SourceElement::createRandom(this, 0) );
	}
	
	// TODO: Generate code for main function instead of just printing?
}

void Program::print(std::ostream& out) 
{
    for (int i = 0; i < this->source_elements.size(); ++i) {
	    this->source_elements.at(i)->print(out, 0);
	}
	printMain(out);
}

void Program::printMain(std::ostream& out)
{
    out << "//" << std::endl << "(function () {" << std::endl;
    
    std::vector<Variable*>::iterator it;
    
    // Call all functions in global scope
    for (it = this->variables->begin(); it != this->variables->end(); ++it) {
        Variable* var = *it;
        if (var->type == FUNCTION_T) 
        {
            // For now assuming object is a zero argument function
            out << "   " << var->name << "();" << std::endl;
        }
    }
    
    // Print all variables in global scope
    int line = 0;
    for (it = this->variables->begin(); it != this->variables->end(); ++it) {
        Variable* var = *it;
        if (var->type == NUMBER_T || var->type == STRING_T) 
        {
            line++;
            out << "   " << "print(" << var->name << "); print(\" (" << line << ") \");" << std::endl;
        }
    }
    
    out << "})();" << std::endl;
}	

