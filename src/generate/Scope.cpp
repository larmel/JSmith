#include "Scope.h"
#include "Variable.h"

#include <cstdlib>
#include <algorithm>
#include <iostream>

Scope::Scope(Scope* p) : parent(p) {
    this->variables = new std::vector<Variable*>();
}

Variable* Scope::getRandomVariable(Type t) {
    // TODO: Recur on parent to get all visible variables
    
    if (this->variables->size() == 0) return NULL;
    int pos = rand() % this->variables->size();
    return this->variables->at(pos);
}

Variable* Scope::generateNewVariable(Type t) {
    std::string identifier = this->getNewRandomIdentifier();
    Variable* var = new Variable(identifier, t);
    
    // Functions have their own scope, but are visible in parent scope
    if (t == OBJECT_T) {
        this->parent->variables->push_back( var );
    } else {
        this->variables->push_back( var );
    }
    return var;
}

std::string Scope::getNewRandomIdentifier() {
    // TODO: Recur on parent to check that it is unique
    // TODO: Be more sophisticated creating identifiers, standard permits unicode characters etc
    const int identifier_length = 5;
    char name[identifier_length + 1];
    do {
	    for (int i = 0; i < identifier_length; i++) {
		    int j = rand() % number_of_valid_identifier_characters;
		    name[i] = valid_identifier_characters[j];
	    }
	    name[identifier_length] = '\0';
	} while (!isUnique(name));
	
	return name;
}

bool Scope::isUnique(std::string identifier) {
    bool local_unique = true;
    std::vector<Variable*>::iterator it;
    for (it = variables->begin(); it != variables->end(); ++it) {
        if ((*it)->name == identifier) {
            local_unique = false;
            break;
        }
    }
    if (this->parent != NULL) {
        return local_unique && parent->isUnique( identifier );
    }
    return local_unique;
}


