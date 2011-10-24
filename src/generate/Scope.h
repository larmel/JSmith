#ifndef SCOPE_H
#define SCOPE_H

#include <vector>
#include <string>

#include "Variable.h"

class Scope 
{
private:
    Scope* parent;
    
protected:
    std::vector<Variable*>* variables;
    
public:
    Scope(Scope* p) : parent(p) { };
    Variable* getRandomVariable(Type t);
    std::string getNewRandomIdentifier();
    
    // TODO: Create and add new variables in scope
};


#endif
