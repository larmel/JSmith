#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "Expression.h"

class Function;


class Statement {
private:	
	Function *parent;
    int type;
	
public:
	

    Statement(Function *parent);
	
	void print(std::ostream& out, unsigned int indentation);
};

#endif
