#ifndef FUNCTION_H
#define FUNCTION_H

#include "statement.h"
#include "identifier.h"
#include "program.h"
#include <map>
#include <cstdlib>
#include <cassert>
#include <iostream>

class Program;


static const char valid_identifier_characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
					   	  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'
					    	  };
					    	  
static const int number_of_valid_identifier_characters = 40;



class Function {
private:
	Function *parent;
	Program *prog;
	std::map<std::string, Identifier> local_identifiers;
	int depth;
	int remaining_subfunctions;
	int remaining_statements;

public:
	
	Function(Function *parent, Program *prog, int depth);
	
	void print(std::ostream& out);
	
	void contents(std::ostream& out);
	
	std::map<std::string, Identifier>* get_local_identifiers();
	
	void add_local_identifier(Identifier x);
	
	// Has to check that this identifier is unique...
	Identifier* new_random_identifier();
	
	void print_tabs(std::ostream& out, int extra);
	
};

#endif
