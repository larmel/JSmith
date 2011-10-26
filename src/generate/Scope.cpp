#include "Scope.h"
#include "Variable.h"

#include <cstdlib>
#include <algorithm>
#include <iostream>

Scope::Scope(Scope* p) : parent(p) {

    // Copy all variables from parent scope to this scope
    if (parent != NULL) {
        this->variables = new std::vector<Variable*>( *(parent->variables) );
    } else {
        this->variables = new std::vector<Variable*>();
    }
}

Variable* Scope::getRandomVariable(Type t) {

    
    // Get all the variables of a type
    std::vector<Variable*> vars_of_type;
    
    for (int i = 0; i<this->variables->size(); i++) {
        if (this->variables->at(i)->type == t) {
            vars_of_type.push_back(this->variables->at(i));
        }
    }
    
    if (vars_of_type.size() == 0) {
        return NULL;
    }
    
    int pos = rand() % vars_of_type.size();
    return vars_of_type[pos];
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


