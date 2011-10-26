#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>

enum Type {
    UNDEFINED_T, NULL_T, BOOLEAN_T, NUMBER_T, STRING_T, OBJECT_T, FUNCTION_T
};

class Variable {
private:
    bool locked;
    
public:
    Type type;
    std::string name;
    
    bool funcBeenUsed;
    
    Variable(std::string s, Type t);
    
    void lock();
    void unlock();
    
    static std::string generateRandomIdentifier();
    
    static int reserved_word_count;
    static std::string reserved_word[];
    
    static int identifier_character_count;
    static char identifier_character[];
};

#endif

