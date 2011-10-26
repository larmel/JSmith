#ifndef RANDOM_H
#define RANDOM_H
#include <cstdlib>

class Random
{
public:
    static void seed(unsigned long );
    static bool flip_coin();
};

#endif
