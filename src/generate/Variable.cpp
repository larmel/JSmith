
#include "Variable.h"

Variable::Variable(std::string s, Type t) {
    this->name = s;
    this->type = t;
    this->funcBeenUsed = false;
}
