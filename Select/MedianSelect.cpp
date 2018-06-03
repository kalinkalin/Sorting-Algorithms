
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

#include "Select.h"
#include "MedianSelect.h"

MedianSelect::MedianSelect() : Select(){  }

int MedianSelect::getMedian(int arr[], int n){
    insertionSort(arr, 0,n);
    return arr[n/2];
}

int MedianSelect::select(int arr[], int l, int r, int k){
    if (k > 0 && k <= r - l + 1){
        int n = r-l+1;

        int i, median[(n+4)/5];
        for (i=0; i<n/5; i++)
            median[i] = getMedian(arr+l+i*5, 5);
        if (i*5 < n){
            median[i] = getMedian(arr+l+i*5, n%5);
            i++;
        }

        int mainMedian = (i == 1)? median[i-1]:select(median, 0, i-1, i/2);

        int pivotIndex = partition(arr, l, r, mainMedian);

        if (pivotIndex-l == k-1)
            return arr[pivotIndex];

        if (pivotIndex-l > k-1)
            return select(arr, l, pivotIndex-1, k);

        return select(arr, pivotIndex+1, r, k-pivotIndex+l-1);
    }

    return INT_MAX;
}

void MedianSelect::swap(int *a, int *b){
    swaps++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

int MedianSelect::partition(int arr[], int l, int r, int x){
    int i;
    for (i=l; i<r; i++){
      if (arr[i] == x)
         break;
    }
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++){
        comparisions++;
        if (arr[j] <= x){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int MedianSelect::insertionSort(int *array, int p, int q){
  int key;
  int j;

  for(int i = p+1; i < q; i ++){
    key = array[i];
    j = i-1;
    comparisions++;
    while(j >= p && key<array[j]){
      swaps++;
      array[j] ^= array[j+1];
      array[j+1] ^= array[j];
      array[j] ^= array[j+1];
      j--;
    }
  }
}
