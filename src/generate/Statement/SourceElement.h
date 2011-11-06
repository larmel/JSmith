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
private:
    // Number of space characters to print
    static const int indentation = 4;

protected:
    // Will either be Program or a FunctionDeclaration
    Scope* scope;
    
    unsigned int depth;
    
public:
    SourceElement(Scope* context, unsigned int parent_depth) : scope(context), depth(parent_depth + 1) { };

    // This class knows about it's subclasses, perhaps not so elegant?
    static SourceElement* createRandom(Scope* parent_scope, unsigned int depth);
    
    // Pure virtual, abstract class TODO: Remove, use overloading instead
    virtual void print(std::ostream &out) = 0;
    
    friend std::ostream& operator<<(std::ostream& out, const SourceElement& e);
};

#endif
