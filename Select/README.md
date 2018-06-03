## Select implementations

My implementations of two types of order statistics algorithm: 
  * **Randomized select** - basing on randomized partition in which pivot is being chosen randomly. Worst-case is still n^2 complexity.
  * **[Median of medians](https://en.wikipedia.org/wiki/Median_of_medians) select** - improved selection algorithm. Pivot is chosen by selecting medians of each 5 consecutive numbers and then median of this partial medians.
  Worst-case of this algorithm is linear.
  
  ### USAGE
  
  There are two input modes and two according flags
