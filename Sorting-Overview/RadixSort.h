/*
 * RadixSort.h
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#ifndef RADIXSORT_H
#define RADIXSORT_H

#include "SortingAlgorithm.h"

class RadixSort : public SortingAlgorithm{
private:
  int base;

public:
	RadixSort(bool isAscending);
	void sort(int* new_array, int new_size);
  void sortAscending(int* new_array, int new_size);
  void sortDescending(int* new_array, int new_size);
	void countingSortDescending(int A[],int size, int base, int pos);
  void countingSortAscending(int A[],int size, int base, int pos);
  void setBase(int base);
  int getMax(int *array, int size);
};

#endif /* RADIXSORT_H_ */
