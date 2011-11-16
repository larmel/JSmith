#include "Variable.h"
#include "Random.h"
#include <cstdlib>

int Variable::reserved_word_count = 29;
std::string Variable::reserved_word[] = {
    "break̈́",  "do", "instanceof", "typeof",
    "case", "else", "new", "var",
    "catch", "finally", "return", "void",
    "continue", "for", "switch", "while",
    "debugger", "function", "this", "with",
    "default", "if", "throw",
    "delete", "in", "try",
    "null",
    "true", "false"
};

int Variable::identifier_character_count = 42;
char Variable::identifier_character[] = {
    '$', '_',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'
};

Variable::Variable(std::string s) {
    this->identifier = s;
    this->locked = false;
}

void Variable::lock() {
    locked = true;
}

void Variable::unlock() {
    locked = false;
}

std::string Variable::generateRandomIdentifier() 
{
    std::string identifier;
    bool is_reserved;
    do {
        identifier = "_";
        do {
            char nextchar = identifier_character[ rand() % identifier_character_count ];
            identifier += nextchar;
        } while (Random::flip_coin());
        
        is_reserved = false;
        for (int i = 0; i < reserved_word_count; ++i) {
            if (identifier == reserved_word[i]) {
                is_reserved = true;
                break;
            }
        }
    } while (is_reserved);
    
	return identifier;
}

std::ostream& operator<<(std::ostream& out, const Variable& e) {
    e.print(out);
    return out;
}



// NumberVariable

NumberVariable::NumberVariable(std::string identifier) : Variable(identifier) {

}

void NumberVariable::print(std::ostream& out) const {
	// TODO chain
	if(this->parent != NULL){
		out << this->parent << ".";
	}
	out << this->identifier;
}


Type NumberVariable::getType() {
    return NUMBER_T;
}



// FunctionVariable

FunctionVariable::FunctionVariable(std::string identifier, int numarg) : Variable(identifier) {
	this->num_arguments = numarg;
}

Type FunctionVariable::getType() {
    return FUNCTION_T;
}

void FunctionVariable::print(std::ostream& out) const {
    //TODO:
    // print some shits
}

// ClassVariable

ClassVariable::ClassVariable(std::string identifier, int numarg) : Variable(identifier){
	this->num_arguments = numarg;
}

Type ClassVariable::getType() {
    return CLASS_T;
}

void ClassVariable::print(std::ostream& out) const {
	if(this->parent != NULL){
		out << this->parent << ".";
	}
	out << "this";
}
