#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "Variable.h"


class Expression {
private:	
    std::string printout;
	
public:

    Expression();
	void print(std::ostream& out);
	
};

#endif
