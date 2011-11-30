#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <cstdlib>
#include <iostream>

#include "SourceElement.h"

class Scope;

class Statement : public SourceElement 
{
public:
    Statement(Scope* context, unsigned int depth) : SourceElement(context, depth) { };
	
	static Statement* newRandomStatement(Scope*, int depth);
};

#endif
