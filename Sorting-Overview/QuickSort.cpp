/*
 * QuickSort.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#include "QuickSort.h"
#include "SortingAlgorithm.h"
#include <iostream>

QuickSort::QuickSort(bool isAscending) : SortingAlgorithm(isAscending){

}
void QuickSort::sort(int* new_array, int new_size){
	start = clock();
	quickSort(new_array,0,new_size-1);
	end = clock();
}

void QuickSort::quickSort(int A[], int p, int q){

	if(p<q){
		int p_ind = partition(A,p,q);
		quickSort(A,p,p_ind-1);
		quickSort(A,p_ind+1,q);
	}
}

int QuickSort::partition(int A[], int p,int q){                 // p - starting index , q - ending index
	int pivot = A[p];													// chose the pivot
	int j = p;
	int i = p+1;
	int temp;

	while(i <= q){
		if(compare(A[i],pivot) == 1){
			j++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
			swaps ++;
		}
		i++;
	}

	temp = A[p];
	A[p] = A[j];
	A[j] = temp;
	swaps ++;

	return j;												// return current pivot position
}

QuickSort::~QuickSort() {
	// TODO Auto-generated destructor stub
}
