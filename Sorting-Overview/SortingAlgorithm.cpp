#include "SortingAlgorithm.h"
#include <functional>
#include <algorithm>
#include <iostream>

SortingAlgorithm::SortingAlgorithm(bool isAscending){
	this->swaps = 0;
	this->ascending = isAscending;

	if(isAscending){
		compare = [=](int number1, int number2) -> int{
			comparisions ++;
			if(number1 >= number2) {
				return 1;
			}
			else {
				return 0;
			}
		};
		compare_ne = [=](int number1, int number2) -> int{
			comparisions ++;
			if(number1 > number2) {
				return 1;
			}
			else {
				return 0;
			}
		};
	}
	else{
		compare = [=](int number1, int number2) -> int{
			comparisions ++;
			if(number1 <= number2) {
				return 1;
			}
			else {
				return 0;
			}
		};

		compare_ne = [=](int number1, int number2) -> int{
			comparisions ++;
			if(number1 < number2) {
				return 1;
			}
			else {
				return 0;
			}
		};
	}
}

int SortingAlgorithm::getSwaps(){
	return swaps;
}
int SortingAlgorithm::getComparisions(){
	return comparisions;
}

double SortingAlgorithm::getTotalTime(){
	double time = (end - start) / (double) CLOCKS_PER_SEC;
	return time;
}

void SortingAlgorithm::resetStats(){
	end = 0;
	start = 0;
	swaps = 0;
	comparisions = 0;
}
