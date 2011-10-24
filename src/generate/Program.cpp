#include "Program.h"
#include "Function.h"

// CLASS PROGRAM
	
Program::Program(){
	//global_identifiers = new std::map<std::string, Identifier>();
}

std::vector<Variable*> Program::context = std::vector<Variable*>();

Program::~Program(){
	//delete global_identifiers;
}

void Program::print(std::ostream& out) {
	
	Function f(NULL, this, 0);
	f.print(out);
    
}

void Program::main(std::ostream& out)
{
	out << "(function main(){ hash = foo(); print(hash); return 0; })();";
}	

