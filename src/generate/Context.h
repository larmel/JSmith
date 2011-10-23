#ifndef CONTEXT_H
#define CONTEXT_H

#include <cstdlib>
#include <vector>
#include "Variable.h"

/*
 * Function and Program has context
 */

class Context
{
private:
    std::vector<Variable*> variables;


public:

    Variable* getRandomVariable(Type t) {
        if (variables.size() == 0) return NULL;
        int pos = rand() % variables.size();
        return this->variables[pos];
    };
    
    void addVariable(Variable* v) {
        this->variables.push_back(v);
    };


};

#endif
