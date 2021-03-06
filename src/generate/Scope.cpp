#include "Scope.h"
#include "Variable.h"
#include "Random.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

Scope::Scope(Scope* p) : parent(p) {
    this->is_function_expression = false;
    this->allowReturn = (p != NULL ? p->allowReturn : false);

    // Copy all variables from parent scope to this scope
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

FunctionVariable* Scope::generateFunctionVariable() {
    std::string identifier = this->getNewRandomIdentifier();

    FunctionVariable* f = new FunctionVariable(identifier, 0);

    // Functions have their own scope, but are visible in parent scope
    this->variables->push_back( f );

	this->setParent(f);
	return f;
}

MapVariable* Scope::generateMapVariable() {
    std::string identifier = this->getNewRandomIdentifier();

    MapVariable* f = new MapVariable(identifier);

    // Maps have their own scope, but are visible in parent scope
    this->variables->push_back( f );
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

ObjectVariable* Scope::generateObjectVariable() {
    std::string identifier = this->getNewRandomIdentifier();

    ObjectVariable* f = new ObjectVariable(identifier);
    f->parent = NULL; // Never property
    return f;
}

/*
 * Add new variables in scope for all properties in classVariable
 */
void Scope::createInstance(ClassVariable* classVariable, Variable* handle) {
    for (int i = 0; i < classVariable->getProperties().size(); ++i) {
        Variable* property = classVariable->getProperties().at(i);
        Variable* copy = property->copyTo( handle );
        this->add( copy );
    }
}

Variable* Scope::getRandomVariable(Type t) {
    // Get all the variables of a type
    std::vector<Variable*> vars_of_type;
    
    for (int i = 0; i < this->variables->size(); i++) {
        Variable* var = this->variables->at(i);
        if (var->getType() == t && !var->is_locked()) {

            // Bugfix: When requesting a variable inside a function expression,
            // do not want properties from parent function expression
            if (is_function_expression && var->parent != NULL) {
                continue;
            }

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
    do {
        name = Variable::generateRandomIdentifier();
    } while (!isUnique(name));
    used_identifiers.push_back(name);
	return name;
}

bool Scope::isUnique(std::string identifier) {
    std::vector<Variable*>::iterator it;
    for (it = variables->begin(); it != variables->end(); ++it) {
        if ((*it)->identifier == identifier) {
            return false;
        }
    }
    if (this->parent != NULL) {
        return parent->isUnique( identifier );
    }
    // New: check global list. No point in reusing identifiers
    std::vector<std::string>::iterator its;
    for (its = used_identifiers.begin(); its != used_identifiers.end(); ++its) {
		if ((*its) == identifier) {
			return false;
		}
	}
    return true;
}

Scope *Scope::getParent(){
    return parent;
}



