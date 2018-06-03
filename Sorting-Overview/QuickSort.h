/*
 * QuickSort.h
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#ifndef QUICKSORT_H_
#define QUICKSORT_H_

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm{

public:
	QuickSort(bool isAscending);
	void sort(int* new_array, int new_size);
	void quickSort(int A[], int p, int q);
	int partition(int A[], int p,int q);
	virtual ~QuickSort();
};

#endif /* QUICKSORT_H_ */
