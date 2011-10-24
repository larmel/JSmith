#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <iostream>

class Variable;
class Function;

//
// Program
//  SourceElement
//   Statement
//   FunctionDeclaration
//    SourceElement


class Program {
private:
    Function* function;
public:
	Program();
	
	~Program();
	
    void print(std::ostream& out);
	
	void main(std::ostream& out);
}; 

#endif
