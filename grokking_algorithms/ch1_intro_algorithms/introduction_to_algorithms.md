
An **algorithm** is a set of instructions for accomplishing a task. Example:
	**Binary search** - Search algorithm that given an input of a sorted list of elements and a target element, it will output the location of the target in the list (or if not there, null). 

**Running time** - how long an algorithm takes to run.

**Big O notation** is used to analyze the speed of an algorithm. It's not measured in seconds, rather in growth of number of operations n (or the running time). So it lets you compare the number of operations for a given input and how this increases asymptotically. 

The **notation** is a big O, followed by the number of operations - i.e. O(n).

**Big O run times** - from fastest to slowest
	- ***Constant*:**  O(1) - A fixed number of operations, regardless of input.
	- ***Logarithmic:*** O(log n) -  Each step reduces the problem size by a constant factor (like 2!)
	- ***Linear:*** O(n) -  Number of operations increases directly proportionally with input size.
	- ***Linearithmic*:** O(n log n) - For each input it requires a logarithmic run time.
	- ***Quadratic*:** O(n^2) - Number of operations increases with the square of input size.
	- ***Cubic*:** O(n^3) - Number of operations increases with the square of input size.
	- ***Polynomial:*** O(n^k) - Number of operations increases with the kth power of input size 
	- ***Exponential*:** O(2^n) - Number of operations doubles with each additional input. (More generally k^n)
	- ***Factorial:***  O(n!) - Fastest growing, increases with the factorial of input size.
	- ***Sub-linear*:** O(n^(1/k)) - The running time grows slower than linear but faster than constant or logarithmic. Only a fraction of the input needs to be examined to produce a result.


**Travelling salesperson** problem - Giving a list of cities, the task is to find shortest path to visit them all. It's considered by some to be impossible to solve faster than with a factorial time algorithm!

Binary search trees

**Exercises**
**1.1** - As you divide the range by half every time, the most steps required to find a name given a list of 128 names is 128 -> 64 -> 32 -> 16 -> 8 -> 4 -> 2 ->1 - 7 steps, or log (128) = 7.

**1.2** - As it's double, it'd take one more halving (step). So, 8 steps or log (256) = 8.

**1.3** - O(log n) assuming binary search

**1.4** - O(n). The list isn't sorted by phone numbers, so you'll have to look through all of them

**1.5** - O(n). It asks to read all the numbers

**1.6** - O(n). It's a subset of all names, but can be considered as its own set of n names.