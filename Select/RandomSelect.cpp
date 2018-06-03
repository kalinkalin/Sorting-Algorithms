/*
 * QuickSort.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#include "RandomSelect.h"
#include "Select.h"
#include <iostream>
#include<climits>

using namespace std;

RandomSelect::RandomSelect() : Select(){}

int RandomSelect::select(int* input, int p, int r, int k){
  if (k > 0 && k <= r - p + 1){
    if (p == r)
      return input[p];

    int j = randomPartition(input, p, r);
    int length = j - p + 1;

    if (length == k)
      return input[j];

    else if (k < length)
      return select(input, p, j - 1, k);

    else
      return select(input, j + 1, r, k - length);
    }

    return INT_MAX;
}

int RandomSelect::randomPartition(int *A, int p, int r)	{
    int i = p + rand() % (r - p + 1);

    swaps ++;
    int temp = A[r];
    A[r] = A[i];
    A[i] = temp;
    int x = A[r];
    i = p - 1;
    for(int j=p; j<r; j++){
      comparisions ++;
      if(A[j] <= x)	{
          i++;
          swaps++;
          temp = A[j];
          A[j] = A[i];
          A[i] = temp;
      }
    }
    swaps++;
    temp = A[r];
    A[r] = A[i+1];
     A[i+1] = temp;
    return i+1;
}


RandomSelect::~RandomSelect() {}
