/*
 * InsertionSort.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: kalinek
 */

#include "InsertionSort.h"
#include <iostream>

InsertionSort::InsertionSort(bool isAscending) : SortingAlgorithm( isAscending) {
}

void InsertionSort::sort(int *array, int size){

	start = clock();

	int key;
	int j;

	for(int i = 1; i < size; i ++){
		key = array[i];
		j = i-1;

		while(j >= 0 && compare_ne(key,array[j]) == 1){
			array[j] ^= array[j+1];
			array[j+1] ^= array[j];
			array[j] ^= array[j+1];
			j--;
			swaps ++;
		}
	}

	end = clock();
}

InsertionSort::~InsertionSort() {
	// TODO Auto-generated destructor stub
}
