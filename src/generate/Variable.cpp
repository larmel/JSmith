
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
    // TODO: Need to check that it is unique
    char navn[5];
	while (true) {
		for (int i = 0; i < 4; i++) {
			int j = rand() % number_of_valid_identifier_characters;
			navn[i] = valid_identifier_characters[j];
		}
		navn[4] = '\0';
		break;
	}
	
	return navn;
}
