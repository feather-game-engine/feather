#include "util.h"

int seed(int seed){
	srand(seed);
	return 0;
}

int range(int low, int high){
	int result = (rand() % (high - low + 1)) + low;
	return result;
}
