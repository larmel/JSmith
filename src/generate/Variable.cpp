#include "Variable.h"
#include <cstdlib>

Variable::Variable(std::string s, Type t) {
    this->name = s;
    this->type = t;
    this->funcBeenUsed = false;
}

std::string Variable::generateRandomIdentifier() {

    const int identifier_length = 5;
    char name[identifier_length + 1];
    for (int i = 0; i < identifier_length; i++) {
	    int j = rand() % number_of_valid_identifier_characters;
	    name[i] = valid_identifier_characters[j];
    }
    name[identifier_length] = '\0';
	
	return name;
}
