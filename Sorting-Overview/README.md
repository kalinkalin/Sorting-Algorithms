## Sorting algorithms overview

To compile just type `make` in TTY in the source code directory.

Implementations of the most popular sorting algorithms : 
  * **insertion sort** - in-place algorithm of square complexity. Working well on small arrays. 
  * **quicksort** - in-place algorithm of worstcase n^2 complexity and nlogn avg complexity. 
  * **dual pivot quicksort** - improved quicksort algorithm which takes less comparisions and swaps. Implemented in 
  [count strategy](https://arxiv.org/pdf/1710.07505.pdf).
  * **radix sort** - algoritm of linear complexity without key values comparisions, using extra memory. Improvement of counting sort algorithm which takes a lot more memory.
  * **merge sort** - not in-place algorithm, taking a lot of extra memory. Worstcase nlogn complexity.
  
  I have been using Cormens "Introduction to Algorithms" while implementing this algorithms and if you want further expalantions i would
  recomend to read it in this book.
  
  <hr>
  
  ### USAGE
  
  There are some programme flags allowing to chose algorithm and order in which we want to sort an array. There are two modes- direct input mode for small arrays and big arrays mode with generating input data. In direct input mode you have to type size of array and than elements of an array.
  
  example of usage : `./main --type merge --order ">="`
  
  After `--type` flag there are possible names of algorithms: `merge`,`insert`,`quick`,`dpquick`,`radix`. After `--order` flag there are possible: `">="` or `"<="`.
  
  
 #### Statistics mode

There is also optional `--stat` flag, which will run test for given algorithm for array sizes 100,200,...,10000 and all of the statistics from this tests will be printed to given text file. After the flag we have to type name of file and after that number of test repetitions for given size, just to be able to get avarage stats. Statistics in files ar in given order: size of data, comparisions, swaps, total sorting time. 

example of usage : `./main --type merge --order ">=" --stat my_file.txt 100`

Example effect:

![](https://image.ibb.co/jHFAOJ/c_n_all.jpg)
*Statistics processed in matlab programme*


