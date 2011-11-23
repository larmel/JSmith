#include "Random.h"

void Random::seed(unsigned long s) {
    srand(s);
}

bool Random::flip_coin() {
    return rand() % 2 == 0;
} 
int Random::randint(int from, int to){
	return rand() % (to-from+1) + from;
}
