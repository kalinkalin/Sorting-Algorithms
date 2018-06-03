## Sorting algorithms overview

To compile just type `make` in TTY in the source code directory.

Implementations of the most popular sorting algorithms : 
  * **insertion sort** - in-place algorithm of square complexity. Working well on small arrays. 
  * **quicksort** - in-place algorithm of worstcase n^2 complexity and nlogn avg complexity. 
  * **dual pivot quicksort** - improved quicksort algorithm which takes less comparisions and swaps. Implemented in 
  [count strategy](https://arxiv.org/pdf/1710.07505.pdf).
  * **radix sort** - algoritm of linear complexity without key values comparisions, using extra memmory. Improvement of counting sort algorithm which takes a lot more memmory.
  * **merge sort** - not in-place algorithm, taking a lot of extra memmory. Worstcase nlogn complexity.
  
  I have been using Cormens "Introduction to Algorithms" while implementing this algorithms and if you want further expalantions i would
  recomend to read it in this book.
  
  <hr>
  
  ### USAGE
  
  
