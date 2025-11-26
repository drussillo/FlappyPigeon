#ifndef RANDOM_H
#define RANDOM_H

#include <random>


namespace Random {

extern std::mt19937 rng;

int range(int min, int max);

}


#endif
