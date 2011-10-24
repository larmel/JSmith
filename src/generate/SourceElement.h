#ifndef SOURCE_ELEMENT_H
#define SOURCE_ELEMENT_H

#include <iostream>

class Scope;

/*
 * SourceElement -> Statement
 *               |  FunctionDeclaration
 */
class SourceElement
{
protected:
    // Will either be Program or a FunctionDeclaration
    Scope* scope;
    
public:
    SourceElement(Scope* context) : scope(context) { };

    // This class knows about it's subclasses, perhaps not so elegant?
    static SourceElement* createRandom(Scope* parent_scope);
    
    // Pure virtual, abstract class
    virtual void print(std::ostream &out, unsigned int depth) = 0;
};

#endif
