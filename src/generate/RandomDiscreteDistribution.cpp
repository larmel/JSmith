#include "RandomDiscreteDistribution.h"

RandomDiscreteDistribution::RandomDiscreteDistribution(int size, ...){

    va_list vl;
    va_start(vl, size);
    
    int values[size];
    float sum = 0;
    
    for (int i=0; i < size;i++)
    {
        values[i] = va_arg(vl, int);
        sum += values[i];
    }
    va_end(vl);
    
    float value = rand() / (float)RAND_MAX;
    
    int chosen = size - 1;
    int acc = 0;
    
    for(int i = 0; i < size - 1; i++){
        if( value < (acc + values[i])/sum ){
            chosen = i;
            break;
        }
        acc += values[i];
    }
    
    this->chosenIndex = chosen;
    
}

int RandomDiscreteDistribution::getChosenIndex(){
    return this->chosenIndex;
}

