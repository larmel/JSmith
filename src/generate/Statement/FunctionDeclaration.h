#ifndef FUNCTION_DECLARATION_H
#define FUNCTION_DECLARATION_H

#include <vector>
#include <iostream>
#include <string>

#include "Scope.h"
#include "SourceElement.h"
#include "Variable.h"

class FunctionDeclaration : public SourceElement, public Scope 
{
private:
    ClassVariable* variable;
    
    std::vector<SourceElement*> source_elements;
    
public:
    FunctionDeclaration(Scope* parent, unsigned int depth) : SourceElement(parent, depth), Scope(parent) { generate(); };
	
    void generate();

    void setParent(Variable* v );

    void print(std::ostream& out);
};

#endif
