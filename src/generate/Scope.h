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
    
public:
    Scope(Scope* p);
    
    FunctionVariable* getRandomFunctionVariable();

    NumberVariable* getRandomNumberVariable();

    ClassVariable* getRandomClassVariable();


	FunctionVariable* generateFunctionVariable(int num_args);
	NumberVariable* generateNumberVariable();

	ClassVariable* generateClassVariable(int num_args);

    virtual void setParent(Variable*);



    void lockIfNotUnique(std::string identifier);
    Scope* getParent();

    std::string getNewRandomIdentifier();
    
    void add(Variable* v) {
        variables->push_back(v);
    }

    /*
     * Generate and return a new variable for this scope
     */
    Variable* generateNewVariable(Type t);

    // Generate instance variable for some scope, function or program
    virtual Variable* generateNewProperty(Type t);

    void print() {
        for (int i = 0; i < this->variables->size(); i++) {
            std::cout << *(variables->at(i)) << ", ";
        }
        std::cout << "\n\n";
    }
};


#endif
