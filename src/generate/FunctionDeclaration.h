#ifndef FUNCTION_DECLARATION_H
#define FUNCTION_DECLARATION_H

#include <vector>
#include <iostream>
#include <string>

#include "Scope.h"
#include "SourceElement.h"

class FunctionDeclaration : public SourceElement, public Scope 
{
private:
    std::string identifier;
    
    std::vector<SourceElement*> source_elements;
    
public:
    FunctionDeclaration(Scope* parent) : SourceElement(parent), Scope(parent) { generate(); };
	
    void generate();
	
    void print(std::ostream& out, unsigned int depth);
};

#endif
