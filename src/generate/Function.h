#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <cstdlib>
#include <cassert>
#include <iostream>

class Variable;
class Program;

class Function {
private:
	
	Function *parent;
	Program *prog;
	int depth;
	int remaining_subfunctions;
	int remaining_statements;

public:
	std::vector<Variable*> context;
	
	Function(Function *parent, Program *prog, int depth);
	
	void print(std::ostream& out);
	
	void contents(std::ostream& out);
	
	void print_tabs(std::ostream& out, int extra);
};

#endif
