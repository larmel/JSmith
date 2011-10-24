#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>

#include "Variable.h"

class Program;

/*
 * Program
 *  Function <- global scope, not printed as function
 *   Function
 *   Function
 */

class Function {
private:
	std::vector<Variable*> context;
	
	Function *parent;
	Program *prog; // Needed?
	int depth;
	int remaining_subfunctions;
	int remaining_statements;

public:
	Function(Function *parent, Program *prog, int depth);
	
	void print(std::ostream& out);
	
	void contents(std::ostream& out);
	
	void print_tabs(std::ostream& out, int extra);
	
    Variable* getRandomVariable(Type t);
    
    std::string getNewRandomIdentifier();
};

#endif
