#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include <iostream>
#include "Type.h"

class Variable;

class Variable {
private:
    bool locked;
    
public:
    std::string identifier;
    Variable* parent;
    
    Variable(std::string s);
    
    void lock();
    void unlock();
    bool is_locked() {
        return locked;
    };

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
    void print(std::ostream& out) const;
    Type getType();
};

class FunctionVariable : public Variable
{
private:
	int num_arguments;
public:
	FunctionVariable(std::string, int);
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

class ClassVariable : public Variable
{
private:
	int num_arguments;
public:
	ClassVariable(std::string, int);
	void print(std::ostream& out) const;
	Type getType();
	int getNumArguments();
};


#endif

