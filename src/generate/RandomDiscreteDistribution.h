#ifndef RANDOM_DD_H
#define RANDOM_DD_H
#include <cstdarg>
#include <cstdlib>

class RandomDiscreteDistribution
{
private:
    int size;
    int chosenIndex;
public:
    RandomDiscreteDistribution(int, ...);
    int getChosenIndex();
};

#endif
