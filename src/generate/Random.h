#ifndef RANDOM_H
#define RANDOM_H

class Random
{
public:
    static void seed(unsigned long s) {
        srand(s);
    }
    
    static bool flip_coin() {
        return rand() % 2 == 0;
    }
};

#endif
