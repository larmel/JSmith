#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>

static const char valid_identifier_characters[] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};

static const int number_of_valid_identifier_characters = 40;


enum Type {
    UNDEFINED_T, NULL_T, BOOLEAN_T, NUMBER_T, STRING_T, OBJECT_T
};

class Variable {
public:
    Type type;
    std::string name;
    
    Variable(Type t = NUMBER_T);
    
    Variable(std::string s, Type t);
};

#endif

