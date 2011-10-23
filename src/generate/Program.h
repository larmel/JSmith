#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <iostream>

class Variable;

class Program {
public:
	static std::vector<Variable*> context;
	
	Program();
	
	~Program();
	
    void print(std::ostream& out);
	
	void main(std::ostream& out);
}; 

#endif
