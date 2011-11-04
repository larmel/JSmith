#ifndef LITERAL_H
#define LITERAL_H 
 
#include <iostream>
#include <cstdlib>
#include <string>
#include "Expression.h"

// Literal, to generate strings (and other literals)

class Variable;
class Scope;
 
class Literal : public Expression {

private:
    std::string literal_val;
    
public:
    Literal(Scope* parent_scope, int depth);
    void print(std::ostream& out, unsigned int depth);
};
 
 
#endif 
