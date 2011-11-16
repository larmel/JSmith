#include "Scope.h"
#include "Variable.h"
#include "Random.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

Scope::Scope(Scope* p) : parent(p) {
    // Copy all variables from parent scope to this scope
    this->allowReturn = p != NULL ? p->allowReturn : false;

    if (parent != NULL) {
        this->variables = new std::vector<Variable*>( *(parent->variables) );
        this->start_depth = this->variables->size();
    } else {
        this->variables = new std::vector<Variable*>();
        this->start_depth = 0;
    }
}

void Scope::setParent(Variable* v ) // Override in FunctionDeclaration, to denote class
{
    v->parent = NULL;
}

bool allowReturn () {
    return allowReturn;
}



FunctionVariable* Scope::getRandomFunctionVariable() {
    return (FunctionVariable*)getRandomVariable(FUNCTION_T);
}

NumberVariable* Scope::getRandomNumberVariable() {
	return (NumberVariable*)getRandomVariable(NUMBER_T);
}

ClassVariable* Scope::getRandomClassVariable() {
	return (ClassVariable*)getRandomVariable(CLASS_T);
}



FunctionVariable* Scope::generateFunctionVariable(int numargs) {
    std::string identifier = this->getNewRandomIdentifier();

    FunctionVariable* f = new FunctionVariable(identifier, numargs);

    // Functions have their own scope, but are visible in parent scope
    this->variables->push_back( f );

	this->setParent(f);
	return f;
}

NumberVariable* Scope::generateNumberVariable(bool set_parent) {
    std::string identifier = this->getNewRandomIdentifier();

    NumberVariable *n = new NumberVariable(identifier);

    this->variables->push_back( n );

    if (set_parent) {
        this->setParent(n);
    }
    return n;
}

ClassVariable* Scope::generateClassVariable(int numargs) {
    std::string identifier = this->getNewRandomIdentifier();

    ClassVariable *c = new ClassVariable(identifier, numargs);

    // Functions have their own scope, but are visible in parent scope
    this->variables->push_back( c );

    this->setParent(c);
    return c;
}




Variable* Scope::getRandomVariable(Type t) {
    // Get all the variables of a type
    std::vector<Variable*> vars_of_type;
    
    for (int i = 0; i < this->variables->size(); i++) {
        Variable* var = this->variables->at(i);
        if (var->getType() == t && !var->is_locked()) {
            vars_of_type.push_back(this->variables->at(i));
        }
    }
    
    if (vars_of_type.size() == 0) {
        return NULL;
    }
    // Pick a random variable of this type
    int pos = rand() % vars_of_type.size();
    return vars_of_type[pos];
}

std::string Scope::getNewRandomIdentifier() {
    std::string name;

    name = Variable::generateRandomIdentifier();
	lockIfNotUnique(name);

	return name;
}

void Scope::lockIfNotUnique(std::string identifier) {
    std::vector<Variable*>::iterator it;
    for (it = variables->begin(); it != variables->end(); ++it) {
        if ((*it)->identifier == identifier) {
            (*it)->lock();
            break;
        }
    }
    if (this->parent != NULL) {
        parent->lockIfNotUnique( identifier );
    }
}

Scope *Scope::getParent(){
    return parent;
}

