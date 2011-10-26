
#include "Variable.h"

Variable::Variable(Type t) {
    this->name = "default_var";
    this->type = t;
    this->funcBeenUsed = false;
}

Variable::Variable(std::string s, Type t) {
    this->name = s;
    this->type = t;
    this->funcBeenUsed = false;
}
