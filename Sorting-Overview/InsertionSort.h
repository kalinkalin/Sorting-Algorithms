/*
 * InsertionSort.h
 *
 *  Created on: Mar 20, 2018
 *      Author: kalinek
 */

#ifndef INSERTIONSORT_H_
#define INSERTIONSORT_H_
#include "SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm{
public:
	InsertionSort( bool isAscending);
	void sort(int *array, int size);
	virtual ~InsertionSort();
};

#endif /* INSERTIONSORT_H_ */
