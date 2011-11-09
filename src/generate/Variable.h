#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include <iostream>
#include "Type.h"



class Variable {
private:
    bool locked;
    

public:
    Type type;
    std::string name;
    
    bool funcBeenUsed;
    bool is_property;
    
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

    friend std::ostream& operator<<(std::ostream& out, const Variable& e);
};

#endif

