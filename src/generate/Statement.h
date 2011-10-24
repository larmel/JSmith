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
    int type;
	
public:
    Statement(Scope* context) : SourceElement(context) { type = rand() % 2; };
	
	void print(std::ostream& out, unsigned int depth);
};

#endif
