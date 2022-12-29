#include "randomnumber.h"
#include <random>
#include <chrono>

namespace Random
{
	unsigned int seed{static_cast<unsigned int>
	(std::chrono::steady_clock::now().time_since_epoch().count())};
	std::mt19937 mt{seed};
}

int Random::get(int min, int max)
{
	std::uniform_int_distribution rand{min,max};
	return rand(mt);
}
