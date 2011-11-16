#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include <iostream>
#include "Type.h"

class Variable {
private:
    bool locked;
    
    // Functions will have a set of properties
    //std::vector<Variable*> properties;

public:
    //Type type;
    std::string identifier;
    Varaible* parent;
    
    //bool funcBeenUsed;

    Variable(std::string s, Type t);
    
    void lock();
    void unlock();
    bool is_locked() {
        return locked;
    };

    // A property is itself a variable
    //bool is_property;

    // Pointer to object for which this property is attached to
    //Variable* attachedObject;
    
    /*std::vector<Variable*> *getObjectProperties() {
        return &properties;
    }*/

    static std::string generateRandomIdentifier();
    
    static int reserved_word_count;
    static std::string reserved_word[];
    
    static int identifier_character_count;
    static char identifier_character[];

    friend std::ostream& operator<<(std::ostream& out, const Variable& e);
    virtual void print(std::ostream& out);
};


class NumberVariable : Variable
{
};

class FunctionVariable : Variable
{
private:
	int num_arguments;
public:
	FunctionVariable(int);
};

class ClassVariable : Variable
{
private:
	int num_arguments;
public:
	ClassVariable(int);
};


#endif

