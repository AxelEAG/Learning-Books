
### **Divide and Conquer**

**Divide and conquer** is a problem solving technique that relies on finding a solvable **base case**, and using recursion to reduce it into that same base.



Functional programming does not use loops but rather only recursion


### **Quicksort**

Quicksort is a sorting algorithm that given an array, does the following:
	1. Pick a pivot
	2. Partition the array into two sub-arrays: elements that are smaller, and elements that are bigger than the pivot.
	3. Repeat the process on the subarrays until finding the base case.

In this case, the base case is:
* 0 element array
* 1 element array
as they require no sorting

Inductive proofs - a way to prove an algorithm works. It has two steps: base case and inductive case.

worst case vs average case
functions take a constant amount of time to run the required operations, so in practice there might be a difference between algorithms
selection sort: O(n^2)
quick sort: O(n log n) on avg, O(n^2) worst case. Hits avg case more often though
merge sort: O(n log n)

worst case for quick sort heavily depends on pivot selection
### **Exercises** 
**4.1**  - 
```python
### Space inefficient (creates copy of list)
def summ(ls: List[int]) -> int:
	if not ls:
		return 0
	
	if len(ls) == 1:
		return ls[0]
	
	return ls[0] + summ(ls[1:])
	
### Better
def summ(ls: List[int]) -> int:
	if not ls:
		return 0
	
	L = len(ls)
	def rec(i: int) -> int:
		if i == L:
			return 0
		return ls[i] + rec(i + 1)
	
	return summ(ls)

```
Can also optimize the next two for space

**4.2** - 
```python
def count(ls: List[int]) -> int:
	if not ls:
		return 0
	
	return 1 + count(ls[1:])

```

**4.3** -
```python
def maxm(ls: List[int]) -> int:
	if len(ls) == 1:
		return ls[0]
	
	smax = maxm(ls[1:])
	if smax > ls[0]:
		return smax
	else:
		return ls[0]
	# OR: return ls[0] if ls[i] > smax else smax
	# OOR: return max(ls[0], maxm[ls[1:]])
```

**4.4** - 
* **Base case:** 1 element in the search range
* **Recursive case:** Splitting list in two and continuing search on the relevant half


Learning Goals:
* Divide and conquer
* Quicksort