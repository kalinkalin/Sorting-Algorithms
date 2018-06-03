/*
 * Select.h
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#ifndef SELECT_H_
#define SELECT_H_
#include <functional>
#include <algorithm>
#include <ctime>
#include <cstdio>

class Select {
protected:
	int comparisions;
	int swaps;

public:
	std::clock_t start;
	std::clock_t end;
	Select();
	virtual int select(int* new_array, int p,int q,int k) = 0;
	int getSwaps();
	int getComparisions();
	double getTotalTime();
	void resetStats();
};

#endif /* SELECT_H_ */
