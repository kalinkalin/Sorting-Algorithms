/*
 * MergeSort.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#include "MergeSort.h"

MergeSort::MergeSort(bool isAscending) : SortingAlgorithm(isAscending) {
}

void MergeSort::sort(int *new_array, int new_size){
	start = clock();
	mergeSort(new_array,0,new_size-1);
	end = clock();
}

void MergeSort::merge(int arr[], int l, int m, int r){

	int a1_size = m - l + 1;
	int a2_size = r - m;
	int a1[a1_size];
	int a2[a2_size];
	int k,i,j;

	for(int i = 0; i < a1_size; i++){
		a1[i] = arr[l+i];
	}
	for(int j = 0; j < a2_size; j++){
		a2[j] = arr[m+1+j];
	}

	i = 0;
	j = 0;
	k = l;

	while(i < a1_size && j < a2_size){

		if(compare(a1[i],a2[j])){
			arr[k] = a1[i];
			i++;
		}
		else{
			arr[k] = a2[j];
			j++;
		}
		k++;
	}

	while(i < a1_size){
		arr[k] = a1[i];
		i++;
		k++;
	}
	while(j < a2_size){
		arr[k] = a2[j];
		j++;
		k++;
	}
}

void MergeSort::mergeSort(int arr[], int l, int r){

	if(l==r){
		return;
	}

	int m = l+(r-l)/2;

	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);

	merge(arr,l,m,r);
}

MergeSort::~MergeSort() {
	// TODO Auto-generated destructor stub
}
