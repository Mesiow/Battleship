#include "Utils.h"

int randomInt(int low, int high)
{
	std::random_device rd;
	std::mt19937 engine(rd());
	std::uniform_int_distribution<int> dist(low, high);

	int number = dist(engine);

	return number;
}