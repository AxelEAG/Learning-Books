Hash functions: A function for converting a string into a number

Some requirements:
	* Deterministic - Given an input, always gives same output
	* Uniqueness - Diff words map to diff keys (minimized as much as possible)
	* Uniform distribution - Should map keys evenly accross the hash

Hash table use them to store key-value pairs that can be retrieved in O(1) by using
the hash output as the index

They are also known as hash maps, maps, dicitonaries, associative arrays.


Use cases:
	* Lookups - great for mapping one thing to another, and looking such thing up
	* Preventing duplicate entries
	* As a cache 

Collisions: When two keys get assigned the same slot
	* One solution: linked list on that slot


Performance:
	* On average, performs search, insert and delete O(1).
	* However, on worst case, performs O(n) on all operations.

This worst-case performance comes from collisions. So one must avoid them. 
A couple factors to avoid collisions are:
	* Low load factor
	* Good hash function

Load factor - # elements / # slots.

Resizing - increasing the size of a table, generally by doubling it.
A good rule of thumb is to resize whenever the load factor approaches 0.7.

Strategies to handle collisions:
	* Separate chaining - linked list of items in same bucket index
	* Open addressing - Probe for next open bucket
	* Quadratic probing
	* Double hashing


Notes:
Look up
 - primary and secondary clustering
 - SHA function
 - FNV-1a, non-cryptographic hashes (xxHash, wyhash), other common hashes?




* Implement a simple hash table with collision strategies, and resizing 

Exercises
5.1 - true
5.2 - false
5.3 - false
5.4 - true
5.5 - D?
5.6 - B, D
5.7 - C, D