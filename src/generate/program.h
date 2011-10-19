#ifndef PROGRAM_H
#define PROGRAM_H

#include <map>
#include "function.h"
#include "identifier.h"

class Program {
	
private:
	std::map<std::string, Identifier> *global_identifiers;
	
public:
	
	Program();
	
	~Program();
	
    void print(std::ostream& out);
	
	void main(std::ostream& out);
	
	std::map<std::string, Identifier>::iterator get_global_identifiers();
	
	void add_global_identifier(Identifier id);
	
}; 

#endif
