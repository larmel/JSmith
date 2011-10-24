#include "Program.h"
#include "SourceElement.h"

Program::Program() : Scope(NULL) {
    // Generate some number of SourceElements
    for (int i = 0; i < 4; ++i) {
	    this->source_elements.push_back( SourceElement::createRandom(this) );
	}
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
    // TODO: Need to calculate and return some sensible summary of all variables (state) in visible scope
	out << "(function main(){ hash = foo(); print(hash); return 0; })();" << std::endl;
}	

