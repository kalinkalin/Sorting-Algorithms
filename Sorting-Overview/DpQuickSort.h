/*
 * DpQuickSort.h
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#ifndef DPQUICKSORT_H_
#define DPQUICKSORT_H_

#include "SortingAlgorithm.h"

class DpQuickSort : public SortingAlgorithm{

public:
	DpQuickSort( bool isAscending);
	void sort(int* new_array, int new_size);
	void quickSort(int A[], int p, int q);
	int partition(int A[], int p,int q, int *lp);
};

#endif /* DPQUICKSORT_H_ */
