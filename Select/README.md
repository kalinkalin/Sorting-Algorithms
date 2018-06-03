## Select implementations

My implementations of two types of order statistics algorithm: 
  * **Randomized select** - basing on randomized partition in which pivot is being chosen randomly. Worst-case is still n^2 complexity.
  * **[Median of medians](https://en.wikipedia.org/wiki/Median_of_medians) select** - improved selection algorithm. Pivot is chosen by selecting medians of each 5 consecutive numbers and then median of this partial medians.
  Worst-case of this algorithm is linear.
  
  <hr>
  
  ### USAGE
  
  There are two input modes and two according flags. 
   * `-p` - input is random permutation of 1,2,...,n set
   * `-r` - input is randomly chosen set of numbers from 1,..,1000 of size n 
    
  There are two parameters typed after programme start, n - size of an array and k- order of element we are looking for. Statistics like time ,swaps and kth number are printed to stdout and current array is printed to stderr, so in case of big arrays it is recommended to redirect stderr to /dev/null.
