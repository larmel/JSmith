#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>

enum Type {
    UNDEFINED_T = 1, NULL_T = 2, BOOLEAN_T = 4, NUMBER_T = 8, STRING_T = 16, OBJECT_T = 32, FUNCTION_T = 64
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
    
    bool is_locked() {
        return locked;
    };
    
    static std::string generateRandomIdentifier();
    
    static int reserved_word_count;
    static std::string reserved_word[];
    
    static int identifier_character_count;
    static char identifier_character[];
};

#endif

