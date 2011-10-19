#ifndef FUNCTION_CPP
#define FUNCTION_CPP

#include "statement.cpp"
#include "identifier.cpp"
#include "program.cpp"
#include <map>

class Program;

class Function {
private:
	Function *parent;
	Program *prog;
	std::map<std::string, Identifier> *local_identifiers;
	int depth;
	
public:
	
	Function(Function *parent, Program *prog, int depth)
	{
		this->parent = parent;
		this->prog = prog;
		this->depth = depth;
	}
	
	void print(std::ostream& out){
		out << "function foo() {"; 
		this->contents(out);
		out << std::endl << "return x++; };" << std::endl;
	}
	
	void contents(std::ostream& out){
		Statement s(this);
		s.print(out);
	}
	
	std::map<std::string, Identifier>* get_local_identifiers()
	{
		return this->local_identifiers;
	}
	
};

#endif