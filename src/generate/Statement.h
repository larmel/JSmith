#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <cstdlib>
#include <iostream>

#include "SourceElement.h"

class Scope;

class Statement : public SourceElement 
{
private:	
    //int type;
	
public:
    Statement(Scope* context) : SourceElement(context) { };
	
	//virtual void print(std::ostream&, unsigned int) = 0;
	static Statement* newRandomStatement(Scope*);
	
};

#endif
