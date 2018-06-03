//============================================================================
// Name        : sorting.cpp
// Author      : Mateusz Kalinowski
// Version     : alpha
// Copyright   : -------
// Description : detailed overview of primary sorting algorithms
//============================================================================

#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <fstream>

#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SortingAlgorithm.h"
#include "DpQuickSort.h"
#include "RadixSort.h"

using namespace std;

void print_array(int *,int);
bool isSorted(int*, int, bool);

int main(int argc, char *argv[]){
	srand(time(NULL));
	SortingAlgorithm* algorithm;
	bool isAscending;
	char* file_name;
	int k;
	char* sorting_type;


	if(strcmp(argv[3],"--order") == 0){
		if(strcmp(argv[4],"<=")==0){
			isAscending = false;
		}
		else if(strcmp(argv[4],">=") == 0){
			isAscending = true;
		}
	}

	else{
		cout << "wrong arguments" << endl;
		return 0;
	}

	if(strcmp(argv[1],"--type") == 0){
		sorting_type = argv[2];
	}

	if(argc == 8){
		if(strcmp(argv[5],"--stat") == 0){
			file_name = argv[6];
			k = atoi(argv[7]);
		}
		else{
			cout << "wrong arguments" << endl;
		}
	}

	if(argc == 5){
		int arr_size;
		cin >> arr_size;
		int array[arr_size];

		for(int i = 0; i < arr_size; i++){
			cin >> array[i];
		}

		if(strcmp(sorting_type,"insert") == 0){
			algorithm = new InsertionSort(isAscending);
		}
		else if(strcmp(sorting_type,"quick") == 0){
			algorithm = new QuickSort(isAscending);
		}
		else if(strcmp(sorting_type,"merge") == 0){
			algorithm = new MergeSort(isAscending);
		}
		else if(strcmp(sorting_type,"dpquick") == 0){
			algorithm = new DpQuickSort(isAscending);
		}
		else if(strcmp(sorting_type,"radix") == 0){
			algorithm = new RadixSort(isAscending);
		}
		else{
			cout << "wrong arguments" << endl;
			return 0;
		}

		algorithm->sort(array,arr_size);
		cerr << endl;
		cerr << "TOTAL COMPARISIONS : " << algorithm->getComparisions() << endl;
		cerr << "TOTAL SWAPS : " << algorithm->getSwaps() << endl;
		cerr << "TOTAL TIME : " << algorithm->getTotalTime() << endl;
		cout << arr_size << endl;
		print_array(array, arr_size);
		algorithm->resetStats();
		bool sorted = isSorted(array,arr_size,isAscending);
		if(!sorted){
			cout << endl;
			cout << "NOT SORTED ARRAY !"<< endl;
		}
	}


	else if(argc == 8){
		if(strcmp(sorting_type,"insert") == 0){
			algorithm = new InsertionSort( isAscending);
		}
		else if(strcmp(sorting_type,"quick") == 0){
			algorithm = new QuickSort( isAscending);
		}
		else if(strcmp(sorting_type,"merge") ==0){
			algorithm = new MergeSort(isAscending);
		}
		else if(strcmp(sorting_type,"dpquick") ==0){
			algorithm = new DpQuickSort(isAscending);
		}
		else if(strcmp(sorting_type,"radix") ==0){
			algorithm = new RadixSort(isAscending);
		}
		else{
			cout << "wrong arguments" << endl;
			return 0;
		}

		ofstream myfile;
    myfile.open (file_name);
		for(int n = 100; n <= 10000; n+=100){
			for(int i = 0; i < k; i++){
				int *rand_array;
				rand_array = (int*)malloc(n*sizeof(int));

				for(int j =0; j <n; j++){
					rand_array[j] = rand() % 100000;
				}
				algorithm->sort(rand_array,n);
				myfile << to_string(n);
				myfile << ",";
				myfile << to_string(algorithm->getComparisions());
				myfile << ",";
				myfile << to_string(algorithm->getSwaps());
				myfile << ",";
				myfile << to_string(algorithm->getTotalTime());
				myfile << ",\n";

				algorithm->resetStats();
			}
		}
		myfile.close();
	}

	else{
		cout << "wrong arguments ! \n" << endl;
	}
}

void print_array(int *array,int array_size){
	for(int i = 0; i < array_size; i++){
		cout << array[i] << " " ;
	}
}
bool isSorted(int* array, int size, bool isAscending){
	if(!isAscending){
		for(int i = 1; i < size; i++){
			if(array[i-1]>array[i]){
				return false;
			}
		}
	}
	if(isAscending){
		for(int i = 1; i < size; i++){
			if(array[i-1]<array[i]){
				return false;
			}
		}
	}
	return true;
}
