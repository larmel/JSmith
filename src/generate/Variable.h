#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "Program.h"
#include "Function.h"

enum Type {
    UNDEFINED_T, NULL_T, BOOLEAN_T, NUMBER_T, STRING_T, OBJECT_T
};

class Variable {
public:
    Type type;
    std::string name;
    
    Variable(Type t = NUMBER_T) {
        this->name =  Variable::getNewRandomIdentifier();
        this->type = t;
    }
    
    Variable(std::string s, Type t) {
        this->name = s;
        this->type = t;
    };
    /*
    static Variable* getRandomLocal(Function* f, Type t) {
        // TODO: Recur on parent functions
        
        if (f->context.size() == 0) return NULL;
        int pos = rand() % f->context.size();
        return f->context[pos];
    };
    
    static Variable* getRandomGlobal() {
        
        if (Program::context.size() == 0) return NULL;
        int pos = rand() % Program::context.size();
        return Program::context[pos];
    };*/
    
    static std::string getNewRandomIdentifier(Function* f = NULL) {
        return "abc";
    }

};

#endif
