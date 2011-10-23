#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>

enum Type {
    UNDEFINED_T, NULL_T, BOOLEAN_T, NUMBER_T, STRING_T, OBJECT_T
};

class Variable {
public:
    Variable(Type t);
//    Variable(string s, Type t = Type::NUMBER_T) : type(t), name(s) { };

    Type type;
    std::string name;
};

#endif
