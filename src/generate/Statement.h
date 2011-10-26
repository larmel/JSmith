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
    Statement(Scope* context, unsigned int depth) : SourceElement(context, depth) { };
	
	//virtual void print(std::ostream&, unsigned int) = 0;
	static Statement* newRandomStatement(Scope*, unsigned int depth);
	
};

#endif
