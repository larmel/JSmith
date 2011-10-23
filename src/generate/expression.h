#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <cstdlib>
#include <iostream>
#include "Variable.h"
#include "function.h"
class Function;


class Expression {
private:	
    Function *function;
    std::string printout;
	
public:
    Expression() {};
    Expression(Function *function);
	void print(std::ostream& out);
	
};

#endif
