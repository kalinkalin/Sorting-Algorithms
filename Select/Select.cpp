#include "Select.h"
#include <functional>
#include <algorithm>
#include <iostream>

Select::Select(){
	this->swaps = 0;
}

int Select::getSwaps(){
	return swaps;
}
int Select::getComparisions(){
	return comparisions;
}

double Select::getTotalTime(){
	double time = (end - start) / (double) CLOCKS_PER_SEC;
	return time;
}

void Select::resetStats(){
	end = 0;
	start = 0;
	swaps = 0;
	comparisions = 0;
}
