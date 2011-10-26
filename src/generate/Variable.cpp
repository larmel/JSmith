#include "Variable.h"
#include "Random.h"
#include <cstdlib>

Variable::Variable(std::string s, Type t) {
    this->name = s;
    this->type = t;
    this->funcBeenUsed = false;
}

std::string Variable::generateRandomIdentifier() 
{
    std::string identifier;
    bool is_reserved;
    do {
        identifier = "";
        do {
            char nextchar = identifier_character[ rand() % identifier_characters ];
            identifier += nextchar;
        } while (Random::flip_coin());
        
        is_reserved = false;
        for (int i = 0; i < reserved_words; ++i) {
            if (identifier == reserverd_word[i]) {
                is_reserved = true;
                break;
            }
        }
    } while (is_reserved);
    
	return identifier;
}
