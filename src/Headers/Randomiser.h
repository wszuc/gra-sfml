#pragma once
#include <random>

using namespace std;

class Randomiser
{
private:
	random_device rd;
public:
	int random(unsigned int from,unsigned int to);
};