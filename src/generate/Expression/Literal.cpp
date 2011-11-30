#include "Literal.h"
#include "Variable.h"
#include "Scope.h"
#include "Random.h"
#include "RandomDiscreteDistribution.h"
#include "Type.h"
#include <climits>
#include <cstdio>
#include <sstream>

Literal::Literal() {
    RandomDiscreteDistribution r(2,
            10,
            0);

    switch (r.getChosenIndex()) {
    case 0:
        this->type = L_NUMERIC;
        this->literal_val = randomNumericLiteral();
        break;
    case 1:
        this->type = L_STRING;
        this->literal_val = randomStringLiteral();
    }
}

std::string Literal::randomNumericLiteral() {
    std::stringstream sst;
    RandomDiscreteDistribution numeric_type (8, 1, 1, 2, 1, 1, 1, 1, 1);

    switch (numeric_type.getChosenIndex()) {
    case 0:
        sst << rand() % INT_MAX;
        break;
    case 1:
        sst << rand() % INT_MAX << "." << rand() % INT_MAX;
        break;
    case 2:
        {
            char buffer[30];
            sprintf(buffer, "0x%x", rand() % INT_MAX);
            sst << buffer;
            break;
        }
    case 3:
        sst << rand() % 10 << "." << rand() % INT_MAX << rand() % INT_MAX << "E" << rand() % 309;
        break;
    case 4:
        sst << "-" << rand() % 1000 << "." << rand() % 100;
        break;
    case 5:
    	sst << 0;
    	break;
    case 6:
    	sst << INT_MAX;
    	break;
    case 7:
    	sst << INT_MAX << rand() % INT_MAX;
    	break;
    }
    return sst.str();
}

std::string Literal::randomStringLiteral() {
    std::string s = "";
    do {
        // Careful with this one! Don't generate any " (double quotes) or backslash
        char nextchar = (rand()%(126-35)+35) ;
        if (nextchar == '\\') continue;
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
