#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>

static const int reserved_words = 29;
static const std::string reserverd_word[] = {
    "break̈́",  "do", "instanceof", "typeof",
    "case", "else", "new", "var",
    "catch", "finally", "return", "void",
    "continue", "for", "switch", "while",
    "debugger", "function", "this", "with",
    "default", "if", "throw",
    "delete", "in", "try",
    "null",
    "true", "false"
};

static const int identifier_characters = 42;
static const char identifier_character[] = {
    '$', '_',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'
};

enum Type {
    UNDEFINED_T, NULL_T, BOOLEAN_T, NUMBER_T, STRING_T, OBJECT_T, FUNCTION_T
};

class Variable {
public:
    Type type;
    std::string name;
    
    bool funcBeenUsed;
    
    Variable(std::string s, Type t);
    
    static std::string generateRandomIdentifier();
};

#endif

