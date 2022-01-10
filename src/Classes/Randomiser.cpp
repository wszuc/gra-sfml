#include "./Headers/Randomiser.h"

int Randomiser::random(unsigned int from, unsigned int to)
{
	mt19937 gen(rd());
	uniform_int_distribution<> dist(from, to);
	return dist(gen);
}