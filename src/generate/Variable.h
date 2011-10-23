#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

enum Type {
    UNDEFINED_T, NULL_T, BOOLEAN_T, NUMBER_T, STRING_T, OBJECT_T
};

class Variable {
public:
    Type type;
    std::string name;
    
    Variable(std::string s, Type t) {
        this->name = s;
        this->type = t;
    };

};

#endif
