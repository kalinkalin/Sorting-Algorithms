/*
 * MedianSelect.h
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#ifndef MEDIANSELECT_H_
#define MEDIANSELECT_H_

#include "Select.h"

class MedianSelect : public Select{

public:
	MedianSelect();
	int select(int* new_array, int p,int q, int k);
	int partition(int A[], int p,int q,int medOfMed);
  int getMedian(int arr[], int n);
  void swap(int *a, int *b);
	int insertionSort(int *arr, int p, int q);
};

#endif /* MEDIANSELECT_H_ */
