#ifndef CONTEXT_H
#define CONTEXT_H

#include <list>
#include "variable.h"

/*
 * Function and Program has context
 */

class Context
{
private:
    std::list<Variable*> variables;


public:

    Variable* getVariable(Type t) {
        return this->variables.first();
    };
    
    void addVariable(Variable* v) {
        this->variables.add(v);
    };


}

#endif
