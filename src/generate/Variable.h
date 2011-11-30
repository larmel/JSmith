#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include <iostream>
#include "Type.h"

class Variable;

class Variable {
protected:
    bool locked;

public:
    std::string identifier;
    Variable* parent;
    Variable(std::string s);
    
    // Create a copy, changing parent
    virtual Variable* copyTo(Variable* handle);

    void lock();
    void unlock();
    bool is_locked() {
        return locked;
    };
    std::string getIdentifier();

    static std::string generateRandomIdentifier();
    

    static int reserved_word_count;
    static std::string reserved_word[];
    
    static int identifier_character_count;
    static char identifier_character[];

    friend std::ostream& operator<<(std::ostream& out, const Variable& e);
    virtual void print(std::ostream& out) const = 0;
    virtual Type getType() = 0;
};


class NumberVariable : public Variable
{
public:
    NumberVariable(std::string);
    Variable* copyTo(Variable* handle);
    void print(std::ostream& out) const;
    Type getType();
};

class FunctionVariable : public Variable
{
private:
	int num_arguments;
public:
	FunctionVariable(std::string, int);
	Variable* copyTo(Variable* handle);
	void print(std::ostream& out) const;
	Type getType();
	int getNumArguments();
};

class MapVariable : public Variable
{
private:
public:
	MapVariable(std::string);
	void print(std::ostream& out) const;
	Type getType();
};

/*
 * Instance variable created with 'new'
 */
class ObjectVariable : public Variable
{
public:
    ObjectVariable(std::string);
    Variable* copyTo(Variable* handle);
    void print(std::ostream& out) const;
    Type getType();
};

/*
 * Function declaration, possible to instantiate like a class
 */
class ClassVariable : public Variable
{
private:
	int num_arguments;
	std::vector<Variable*> properties;
public:
	ClassVariable(std::string, int);
	void print(std::ostream& out) const;
	Type getType();
	int getNumArguments();
	void addProperty(Variable* v);
	std::vector<Variable*> getProperties();
};


#endif
