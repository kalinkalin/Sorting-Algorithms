#include "SortingAlgorithm.h"
#include "RadixSort.h"
#include <iostream>
using namespace std;

RadixSort::RadixSort(bool isAscending) : SortingAlgorithm(isAscending){
  base = 10;
}

void RadixSort::sort(int* array, int size){
  if(!ascending){
    sortAscending(array,size);
  }
  else{
    sortDescending(array,size);
  }
}

void RadixSort::sortDescending(int* array, int size){
  start = clock();
  int max = getMax(array,size);

  for(int i =1; max/i > 0; i*=10){
    countingSortDescending(array,size,base,i);
  }
  end = clock();
}


void RadixSort::countingSortDescending(int A[],int size, int base, int pos){
  int C[base]={0};
  int B[size];

  for(int i=0; i < size; i ++)
    C[(A[i]/pos)%base]++;

  for(int i = base-1; i > 0; i--)
    C[i-1]+= C[i];

  for(int i = size - 1; i >= 0; i-- ){
    B[C[(A[i]/pos)%base]-1] = A[i];
    C[(A[i]/pos)%base]--;
  }

  for (int i = 0; i < size; i++)
    A[i] = B[i];
}


void RadixSort::sortAscending(int* array, int size){
  start = clock();
  int max = getMax(array,size);

  for(int i =1; max/i > 0; i*=10){
    countingSortAscending(array,size,base,i);
  }
  end = clock();
}

void RadixSort::countingSortAscending(int A[],int size, int base, int pos){
  int C[base]={0};
  int B[size];

  for(int i=0; i < size; i ++)
    C[(A[i]/pos)%base]++;

  for(int i = 1; i < base; i++)
    C[i] += C[i-1];

  for(int i = size - 1; i >= 0; i-- ){
    B[C[(A[i]/pos)%base]-1] = A[i];
    C[(A[i]/pos)%base]--;
  }

  for (int i = 0; i < size; i++)
    A[i] = B[i];
}

int RadixSort::getMax(int A[], int size){
  int currentMax = A[0];

  for(int i =1; i < size; i++){
    if(A[i] > currentMax){
      currentMax = A[i];
    }
  }
  return currentMax;
}

void RadixSort::setBase(int n_base){
  base = n_base;
}
