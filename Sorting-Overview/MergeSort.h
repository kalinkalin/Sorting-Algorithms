/*
 * MergeSort.h
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_
#include "SortingAlgorithm.h"

class MergeSort : public SortingAlgorithm {

public:
	MergeSort(bool isAscending);
	void merge(int arr[], int l, int m, int r);
	void mergeSort(int arr[], int l, int r);
	void sort(int *new_array, int new_size);
	virtual ~MergeSort();
};

#endif /* MERGESORT_H_ */
