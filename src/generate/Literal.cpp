#include "Literal.h"
#include "Variable.h"
#include "Scope.h"
#include "Random.h"
#include <cstdio>

// Literal, to generate strings (and other literals)

Literal::Literal(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {
    do {
        // Careful with this one! Don't generate any " (double quotes)
        char nextchar = (rand()%(126-35)+35) ;
        this->literal_val += nextchar;
    } while (Random::flip_coin() || Random::flip_coin());
}

void Literal::print(std::ostream& out) const {
    // Print literal
    out << "\"" << literal_val << "\"";
}


std::ostream& operator<<(std::ostream& out, const Literal& e) {
    e.print(out);
    return out;
}

