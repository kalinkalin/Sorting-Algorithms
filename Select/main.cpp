#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>

#include "Select.h"
#include "RandomSelect.h"
#include "MedianSelect.h"

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void printUsage(){
  cout << endl;
  cout << " USAGE: " << endl;
  cout << "  flag `-p` random permutation of n size set" << endl;
  cout << "  flag `-r` randomized set of n size" << endl;
}

void print(int *A, int size)
{
  for (int i = 0; i <size; i++){
      cerr << A[i] << " ";
  }
  cout << endl;
}

int main(int argc, char *argv[]){
  srand (time(NULL));
  int size;
  int stat;
  int testArray[size];

  if(argc == 2){
    if(strcmp(argv[1],"-r") == 0){
      for(int i = 0; i < size; i ++){
        testArray[i] = random()%1000;
      }
    }
    else if(strcmp(argv[1],"-p") == 0){
      for(int i =0; i < size; i++){
        testArray[i] = i;
      }
      for(int i =0; i < size; i++){
        swap(testArray[i],testArray[random()%size]);
      }
    }
    else{
      printUsage();
      return 1;
    }
  }
  else{
    printUsage();
    return 1;
  }

  cin >> size;
  cin >> stat;

  print(testArray,size);
  Select* randomSelect = new RandomSelect();
  Select* medianSelect = new MedianSelect();
  int arrayCopy1[size];
  int arrayCopy2[size];
  memcpy(arrayCopy1,testArray,size*sizeof(int));
  memcpy(arrayCopy2,testArray,size*sizeof(int));

  cout << "(random select) :" << endl;
  randomSelect->start = clock();
  int rsResult = randomSelect->select(arrayCopy1,0,size-1,stat);
  randomSelect->end = clock();
  cout << endl;
  cout << "   K-ta liczba w tablicy to :" <<  rsResult << endl;
  cout << "   Całkowity czas : " << randomSelect->getTotalTime() << endl;
  cout << "   Liczba porównań : " << randomSelect->getComparisions() << endl;
  cout << "   Liczba przestawień : " << randomSelect->getSwaps() << endl;
  cout << endl;

  cout << "(median select) :" << endl;
  medianSelect->start = clock();
  int msResult = medianSelect->select(arrayCopy1,0,size-1,stat);
  medianSelect->end = clock();
  cout << "   K-ta liczba w tablicy to :" << msResult << endl;
  cout << "   Całkowity czas : " << medianSelect->getTotalTime() << endl;
  cout << "   Liczba porównań : " << medianSelect->getComparisions() << endl;
  cout << "   Liczba przestawień : " << medianSelect->getSwaps() << endl;
}
