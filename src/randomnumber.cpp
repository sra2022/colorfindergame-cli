#include "randomnumber.h"
#include <random> //for std::mt19937 & std::uniform_int_distribution
#include <chrono> //for std::chrono

namespace Random
{
	unsigned int seed{static_cast<unsigned int>
	(std::chrono::steady_clock::now().time_since_epoch().count())};
	std::mt19937 mt{seed};
}

//random number generator
int Random::get(int min, int max)
{
	std::uniform_int_distribution rand{min,max};
	return rand(mt);
}

