
#include "Program.h"
#include "Variable.h"
#include "Function.h"

Variable::Variable(Type t) {
    this->name =  Variable::getNewRandomIdentifier();
    this->type = t;
}

Variable::Variable(std::string s, Type t) {
    this->name = s;
    this->type = t;
}

Variable* Variable::getRandomLocal(Function* f, Type t) {
    // TODO: Recur on parent functions
    
    if (f->context.size() == 0) return NULL;
    int pos = rand() % f->context.size();
    return f->context[pos];
}

Variable* Variable::getRandomGlobal() {
    if (Program::context.size() == 0) return NULL;
    int pos = rand() % Program::context.size();
    return Program::context[pos];
}

std::string Variable::getNewRandomIdentifier(Function* f) {
    return "abc";
}
