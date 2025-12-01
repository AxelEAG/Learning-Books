
### **Divide and Conquer**

**Divide and conquer** is a problem solving technique that breaks down a problem into smaller subproblems of the same type.

The algorithms follow the general structure:
1. **Base case** – a simplest-possible subproblem that can be solved directly.
2. **Divide** – split the current problem into smaller parts.
3. **Conquer** – solve each part (often using recursion).
4. **Combine** – merge the partial results into the final solution.

Divide-and-conquer algorithms naturally align with mathematical **induction**, which is often used to prove they work correctly.

**Induction** has two steps:
* **Base case:** Show the algorithm is correct for the simplest possible input
* **Inductive step:** Assume the algorithm works for smaller inputs, and use that assumption to prove it works for a general input.

This is why the proofs of these algorithms may feel so natural, as they directly map to their proof.

### **Quicksort**

Quicksort is a divide and conquer sorting algorithm that works as follows:
1. Picks a pivot
2. Partitions the array into two sub-arrays: 
	* elements smaller than the pivot
	* elements bigger than the pivot
3. Recursively sorts the two sub-arrays
4. Combine results: [sorted smaller] + pivot + [sorted bigger]

The **base case** is an array with 0 or 1 elements, as they require no sorting.

### **Exercises** 
**4.1**  - A recursive summation function can be written as follows
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
	
	return rec(ls)

```
Can also optimize the next two for space

**4.2** - A recursive counting function can be written as follows
```python
def count(ls: List[int]) -> int:
	if not ls:
		return 0
	
	return 1 + count(ls[1:])

```

**4.3** - A recursive maximum finding function can be written as follow
```python
def maxm(ls: List[int]) -> int:
	if len(ls) == 1:
		return ls[0]
	
	smax = maxm(ls[1:])
	if smax > ls[0]:
		return smax
	else:
		return ls[0]
	# OR: return ls[0] if ls[0] > smax else smax
	# OOR: return max(ls[0], maxm[ls[1:]])
```

**4.4** - These are the two cases for binary search:
* **Base case:** 1 element in the search range
* **Recursive case:** Splitting list in two and continuing search on the relevant half

**4.5** - Printing every value in an array would take O(n), as it must touch all of them once.

**4.6** - For the same reason, doubling each value takes O(n) too.

**4.7** - As it's a single element, it's constant regardless of the array size. So, it's O(1).

**4.8** - As it requires to multiply all elements with each other, it does n operations for each of the n elements. That is, O(n²)
