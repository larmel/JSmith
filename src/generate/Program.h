#ifndef PROGRAM_H
#define PROGRAM_H

#include <vector>
#include <iostream>

#include "Scope.h"

class SourceElement;

/*
 * Program
 *  SourceElement (Statement)
 *  SourceElement (FunctionDeclaration)
 *  ...
 */
class Program : public Scope 
{
private:
    std::vector<SourceElement*> source_elements;
    
public:
	Program();
	
	virtual Variable* generateNewProperty(Type t) {
        Variable* v = Scope::generateNewProperty(t);
        v->attachedObject = NULL;
    }

    void print(std::ostream& out);
	void printMain(std::ostream& out);
};

#endif
