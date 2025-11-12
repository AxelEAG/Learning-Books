### **Data Structures**

**Memory** works as a giant storage that can be accessed through addresses.

There's two basic ways to store multiple items: arrays and lists

### **Storing Multiple Items**

**Arrays:**  Store items contiguously in memory. Items are numbered within it, and their position is referred to as **index**. So, given an index of an item, and the start of the array, it is straightforward to calculate the address of the same. This is referred to as having **random access** to any given element.

**Linked Lists:**  Store items along with the address of the next item. This means, just like in the array, items can be read one after another in order- referred to as **sequential access** -, but in this case, they cannot be randomly accessed. 

### **Arrays vs Linked Lists**

**Reading** is quicker on arrays, as they have the advantage of random access - done with a single operation: O(1). On the other hand, linked lists must do it sequentially: in O(n), as they must visit all the preceding elements.

**Insertion** and **deletion** are quicker on linked lists, as they only require to modify the address of the previous element - done with a single operation: O(1). On the other hand, arrays require all elements after the inserted / deleted one to be shifted in their address - requiring n operations: O(n). 

Below, the **time complexities** of the main relevant operations are summarized: 

| Operation | Arrays | Lists |
| :-------: | :----: | :---: |
|  Reading  |  O(1)  | O(n)  |
| Insertion |  O(n)  | O(1)  |
| Deletion  |  O(n)  | O(1)  |

One must notice, even though the insertion / deletion operation is O(1) or O(n), the relevant element must still be **found first**. As such, the real world complexity may be dependent on the time it takes to **search** it- often times requiring a linear search: O(n). 

**Searching** could be done more efficiently than a linear search on arrays, but this requires them to be **sorted**. So, in the next section, a simple way to sort an array will be explored.

### **Selection sort**

[Selection sort](./selection_sort.ipynb) is one of the most straightforward ways of sorting. In short, it separates the list into two parts: a sorted section and an unsorted section. Repeatedly, it scans the unsorted part to find the next smallest element, removes it, and appends it to the sorted section. This process continues until the entire list is sorted.

As mentioned, selection sort is one of the simplest ones - but not the only one. In future sections, alternative, potentially more efficient sorting algorithms will be explored.

### **Exercises**

**2.1** - As in this case insertion is more common than reading, it's best to optimize for it. That is, a linked list would be preferred.

**2.2** - An order queue might be best implemented with a linked list. The end of the queue can be the head of the linked list. In this way, as orders are finished, one can move to the next order on the linked list. In a similar fashion, new orders could be added to the tail of the linked list.

**2.3** - To optimize for searching, assuming the usernames are ordered, an array is best so that binary search can be done. Linked lists would still require to be visited sequentially as they don't have random access.

**2.4** - The order must be maintained to use binary search. As such, elements must be inserted in the right position on the arrays. This can be a downside, as insertion is not optimized on arrays.

**2.5** - A comparison of the operations for the 3 data structures can be as follows:
* **Lookup**
	* **Array** - It has random access, so can binary search it: O(log n)
	* **Linked List** - Only has sequential access, so has to look through it all: O(n).
	* **Hybrid** - Random access for first letter, so it can binary search that part. However, only sequential access for the rest, so it has to look through all elements. So, faster than linked list but slower than array.
* **Insertion / Deletion**  
	These operations still require the lookup previously mentioned, so that part will be omitted.
	* **Array** - Requires to shift all elements after it: O(n).
	* **Linked List** - Only needs to modify the address the previous node points to: O(1).
	* **Hybrid** - Inserts into linked list: O(1). So, lookup slower than array but faster than linked list. However, insertion is faster than array and as fast as linked list. All in all, faster than both.

