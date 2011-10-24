#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>

class Function;

enum Type {
    UNDEFINED_T, NULL_T, BOOLEAN_T, NUMBER_T, STRING_T, OBJECT_T
};

class Variable {
public:
    Type type;
    std::string name;
    
    Variable(Type t = NUMBER_T);
    
    Variable(std::string s, Type t);
    
    static Variable* getRandomLocal(Function* f, Type t);
    
    static Variable* getRandomGlobal();
    
    static std::string getNewRandomIdentifier(Function* f = NULL);
};

#endif

