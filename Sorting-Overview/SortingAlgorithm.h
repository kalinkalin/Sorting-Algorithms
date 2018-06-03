/*
 * SortingAlgorithm.h
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#ifndef SORTINGALGORITHM_H_
#define SORTINGALGORITHM_H_
#include <functional>
#include <algorithm>
#include <ctime>
#include <cstdio>

class SortingAlgorithm {
protected:
	bool ascending;
	int comparisions;
	int swaps;
	std::clock_t start;
	std::clock_t end;
	std::function<int (int, int)> compare;
	std::function<int (int, int)> compare_ne;

public:
	SortingAlgorithm(bool isAscending);
	virtual void sort(int* new_array, int new_size) = 0;
	int getSwaps();
	int getComparisions();
	double getTotalTime();
	void resetStats();
};

#endif /* SORTINGALGORITHM_H_ */
