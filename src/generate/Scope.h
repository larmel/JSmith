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
    
    // TODO: Make this private
    std::string getNewRandomIdentifier();
    
    /*
     * Generate and return a new variable for this scope
     */
    Variable* generateNewVariable(Type t);
};


#endif
