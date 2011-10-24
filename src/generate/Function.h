#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>

#include "Variable.h"

class Program;
class Statement;

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
	
	std::string identifier;
	std::vector<Statement*> statement_list;
	std::vector<Function*> function_list;
	
	int depth;
	int remaining_subfunctions;
	int remaining_statements;

public:
	Function(Function *parent, int depth);
	void generate();
	void print(std::ostream& out, unsigned int indentation);
	
	//void print_tabs(std::ostream& out, int extra);
	
    Variable* getRandomVariable(Type t);
    
    std::string getNewRandomIdentifier();
};

#endif
