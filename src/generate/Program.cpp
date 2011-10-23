#include "Program.h"
#include "Context.h"
#include "Variable.h"

// CLASS PROGRAM
	
Program::Program(){
	//global_identifiers = new std::map<std::string, Identifier>();
}

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
/*
std::map<std::string, Identifier>::iterator Program::get_global_identifiers()
{
	return this->global_identifiers->begin();
}

void Program::add_global_identifier(Identifier id)
{
	(*this->global_identifiers)[id.name] = id;
}
	*/
