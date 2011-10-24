#include "Scope.h"
#include "Variable.h"
#include <cstdlib>

Variable* Scope::getRandomVariable(Type t) {
    // TODO: Recur on parent to get all visible variables
    
    if (this->variables->size() == 0) return NULL;
    int pos = rand() % this->variables->size();
    return this->variables->at(pos);
}

Variable* Scope::generateNewVariable(Type t) {
    std::string identifier = this->getNewRandomIdentifier();
    Variable* var = new Variable(identifier, t);
    this->variables->push_back( var );
    return var;
}

std::string Scope::getNewRandomIdentifier() {
    // TODO: Recur on parent to check that it is unique
    
    char name[5];
	while (true) {
		for (int i = 0; i < 4; i++) {
			int j = rand() % number_of_valid_identifier_characters;
			name[i] = valid_identifier_characters[j];
		}
		name[4] = '\0';
		break;
	}
	
	return name;
}
