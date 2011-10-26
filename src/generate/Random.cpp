#include "Random.h"

void Random::seed(unsigned long s) {
    srand(s);
}

bool Random::flip_coin() {
    return rand() % 2 == 0;
} 
