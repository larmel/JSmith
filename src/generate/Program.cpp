#include "Program.h"
#include "SourceElement.h"
#include "Variable.h"
#include "VariableStatement.h"
#include "FunctionDeclaration.h"
#include "CallStatement.h"
#include "Random.h"
#include <vector>
#include <string>

Program::Program() : Scope(NULL) {

    // Global variables where side effects can be observed
	int globvars = Random::randint(1,10) + Random::randint(0,10);
    for (int i = 0; i < globvars; i++) {
        this->source_elements.push_back( new VariableStatement(this, 0));
    }

    // Guarantee at least one "class"
    this->source_elements.push_back( new FunctionDeclaration(this, 0) );

    // Generate some number of SourceElements
    int sourceelements = Random::randint(1,5);
    for (int i = 0; i < sourceelements; ++i) {
	    this->source_elements.push_back( SourceElement::createRandom(this, 0) );
	}

    while (this->getRandomFunctionVariable() != NULL) {
        this->source_elements.push_back( new CallStatement(this, 0) );
    }

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
    
    // Print all variables in global scope, look for side effects
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
