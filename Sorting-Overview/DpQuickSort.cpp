/*
 * QuickSort.cpp
 *
 *  Created on: Mar 24, 2018
 *      Author: kalinek
 */

#include "DpQuickSort.h"
#include "SortingAlgorithm.h"
#include <iostream>

DpQuickSort::DpQuickSort(bool isAscending) : SortingAlgorithm(isAscending){

}
void DpQuickSort::sort(int* new_array, int new_size){
	start = clock();
	quickSort(new_array,0,new_size-1);
	end = clock();
}
void DpQuickSort::quickSort(int A[], int p, int q){
    if(p< q){
      int lp;
      int rp = partition(A,p,q,&lp);
      quickSort(A,p,lp-1);
      quickSort(A,lp+1,rp-1);
      quickSort(A,rp+1,q);
    }
}

int DpQuickSort::partition(int A[],int p, int q, int* lp){
  int l_pivot;
  int p_pivot;
  int i,j,k;
  int diff = 0;

	comparisions --;
  if(compare_ne(A[q], A[p])){
    l_pivot = A[q];
    p_pivot = A[p];
  }
  else{
    l_pivot = A[p];
    p_pivot = A[q];
  }

  i = p+1;
  j = p+1;
  k = q-1;
  int temp;

  while(j <= k){
    if(diff >= 0 ){
      if(compare_ne(A[j], l_pivot)==1){
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j++;
        diff++;
				swaps ++;
      }
      else{
        if(compare_ne(A[j],p_pivot)==1){
          j++;
        }
        else{
          temp = A[j];
          A[j] = A[k];
          A[k] = temp;
          k--;
          diff--;
					swaps ++;
        }
      }
    }

    else{
      if(compare_ne(p_pivot,A[k])==1){
        k--;
        diff--;
      }
      else{
        if(compare_ne(A[k],l_pivot)==1){
          temp = A[k];
          A[k] = A[j];
          A[j]=A[i];
          A[i] = temp;
          i++;
          diff++;
					swaps++;
        }
        else{
          temp = A[j];
          A[j] = A[k];
          A[k] = temp;
					swaps ++;
        }
        j++;
      }
    }
  }
  A[p] = A[i-1];
  A[i-1] = l_pivot;
  A[q] = A[k+1];
  A[k+1] = p_pivot;
	swaps +=2;

  *lp = i-1;
  return k+1;

}
