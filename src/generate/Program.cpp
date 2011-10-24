#include "Program.h"
#include "Function.h"

Program::Program() {
	this->function = new Function(NULL, this, 0); 
}

Program::~Program() {
    delete this->function;
}

void Program::print(std::ostream& out) {
	function->print(out);
}

void Program::main(std::ostream& out)
{
	out << "(function main(){ hash = foo(); print(hash); return 0; })();";
}	

