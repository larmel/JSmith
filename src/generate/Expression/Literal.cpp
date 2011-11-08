#include "Literal.h"
#include "Variable.h"
#include "Scope.h"
#include "Random.h"
#include "RandomDiscreteDistribution.h"
#include <cstdio>

Literal::Literal(Scope* parent_scope, int depth) : Expression(parent_scope, depth) {

    RandomDiscreteDistribution r (4, 1, 1, 1, 1);

    switch (r.getChosenIndex()) {
    case 0:
        this->type = L_NULL;
        this->literal_val = "null";
        break;
    case 1:
        this->type = L_BOOLEAN;
        this->literal_val = Random::flip_coin() ? "true" : "false";
        break;
    case 2:
        this->type = L_NUMERIC;
        this->literal_val = randomNumericLiteral();
        break;
    case 3:
        this->type = L_STRING;
        this->literal_val = randomStringLiteral();
        break;
    }
}

std::string Literal::randomNumericLiteral() {
    return "42";
}

std::string Literal::randomStringLiteral() {
    std::string s = "";
    do {
        // Careful with this one! Don't generate any " (double quotes)
        char nextchar = (rand()%(126-35)+35) ;
        s += nextchar;
    } while (Random::flip_coin() || Random::flip_coin());
    return s;
}

void Literal::print(std::ostream& out) const {
    switch (type) {
    case L_NULL:
    case L_BOOLEAN:
    case L_NUMERIC:
        out << literal_val;
        break;
    case L_STRING:
        out << "\"" << literal_val << "\"";
    }
}

std::ostream& operator<<(std::ostream& out, const Literal& e) {
    e.print(out);
    return out;
}
