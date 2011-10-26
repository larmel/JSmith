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
    int start_depth; // Index to the first vector element in this scope 
    
    std::string getNewRandomIdentifier();
    
public:
    Scope(Scope* p);
    
    Variable* getRandomLocalVariable(Type t);
    Variable* getRandomVariable(Type t);

    bool isUnique(std::string identifier);
    Scope* getParent();
    
    /*
     * Generate and return a new variable for this scope
     */
    Variable* generateNewVariable(Type t);
};


#endif
