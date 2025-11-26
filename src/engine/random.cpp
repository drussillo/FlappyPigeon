#include "engine/random.h"

#include <random>


std::mt19937 Random::rng(std::random_device{}());

int Random::range(int min, int max) {
  std::uniform_int_distribution<int> gen(min, max);
  return gen(rng);
}
