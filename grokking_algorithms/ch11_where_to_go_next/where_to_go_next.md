
The chapter is a brief overview of 10 algorithms. 
Collected some notes to refer back on them and pick something to look deeper into


1. Trees 

	Trees are data structures made of nodes, connected in a hierarchy.
						
	Binary search tree (BST) 
	Trees where, for every node,
	    left children values are all smaller than it
	    right children values are all bigger than it

	Each comparison can on average discard about half of the remaining tree, so
	most operations (search, insert, delete) are O(log N).

	However, in the worst case they can still be O(N), like if they are inserted
	in sorted order (such that the tree is a single line).

	Other useful tree types:
		* B-trees: Wide, balanced trees designed to work efficiently with disks and databases.
		* Red-black trees: Self-balanced BST that guarantess O(log N) operations.
		* Heaps: Trees optimized for repeatedly retrieving the smallest or largest item.
		* Splay trees: Trees that move recently accessed nodes closer to the root, useful for when the same items are accessed repeatedly

2. Inverted Indexes

	An inverted index maps a word to a document that contains it. 
	
	They are commonly used by search engines because they make it fast to find 
	a document given a word or phrase.

3. Fourier Transform

	The fourier transform breaks a signal into the frequencies that make it up.

	It's got many use cases, along which include:
		* Audio processing and compression
		* Image processing and compression
		* Noise reduction
		* Signal analysis
		* Identifying songs, like Shazam does

4. Parallel Algorithms

	For a long time, programs became faster mostly because processors could execute instructions faster.

	Modern processors have reached practical limits in clock speed and power usage, 
	so performance improvements are more and more coming from using multiple CPU cores simultaneously.

	This is called parallelism.
			
	The speedup is not usually linear. Using four cores does not necessarily make a program four times faster because of:
        * Coordination overhead: Creating tasks, synchronizing threads, and combining results costs time.
        * Load balancing: Some tasks may finish earlier, leaving some cores idle.
        * Parts that cannot be parallelized: A program is only as parallel as its most sequential section

	Parallel quicksort can be made to achieve O(N) sorting time

5. Distributed Algorithms

	Distributed algorithms allow to split work accross many machines, rather than across cores in one computer.

	MapReduce is one such algorithm that allows processing queries much faster by splitting up the work into 
	different machines.
		
	It follows two main ideas:
		* Map: Apply the same operation independently to many inputs.
        * Reduce: Combine those partial results into a final result.


6. Probabilistc Algorithms

	Probabilistic data structures trade exact answers for significantly lower memory use and fast lookups.

	They are useful when working with enourmous data sets where an exact answer is too costly.

	Some examples are:

	I. Bloom Filters
		
	A Bloom filter can quickly answer:
        * “This item is definitely not in the set.”
        * “This item is probably in the set.”
	
	That is, it can produce false positions (saying an item is present when it is not),
	but it cannot produce false negatives (saying an item is absent when it is not).
		
	Use cases:
	    * Avoiding unnecessary database lookups
        * Web crawlers checking whether a URL was already visited
        * URL shorteners or caching systems
        * Checking whether content may already exist

	II. HyperLogLog
    
	HyperLogLog estimates the number of unique items in a huge set while using very little memory.
	
 	For example:
	    * Approximate unique website visitors
        * Approximate unique links discovered by a crawler
        * Approximate unique posts, users, or search queries

	It does not store every item, so it gives an estimate rather than an exact count.


 7. Secure Hash Algorithm
		
	SHA refers to a family of cryptographic hash functions.

	A hash function takes arbitrary input and produces a fixed-size output called a hash or digest.		

	Useful properties:	
	    * The same input always produces the same hash.
	    * Locality-Sensitive: A tiny input change produces a very different hash.
	    * It is computationally infeasible to reconstruct the original input from its hash.
	    * It should be hard to find two different inputs with the same hash.			

	Uses include:
        * Checking file integrity
        * Detecting changes in data
		* Digital signatures
		* Content-addressed storage

8. Locality-Sensitive Hashing

	Normal cryptographic hashes are designed so similar inputs produce completely different hashes.
	
	Locality-sensitive hashing does the opposite: similar inputs tend to produce similar hashes.
	
	For example, SimHash can help detect documents that are almost the same even if a few words differ.
		
	Uses include:
	    * Near-duplicate webpage detection
		* Detecting copied or highly similar documents
		* Recommendation systems
		* Finding similar images, audio, or text

8. Diffie-Hellman Key Exchange

	If two people want to communicate securely, they need a shared secret key. But sending that key directly would let an attacker intercept it.

	Diffie–Hellman solves this key-sharing problem. It lets both parties create the same shared secret over a public channel without ever transmitting that secret itself.	

	Important clarification:
        * Diffie–Hellman is a key exchange algorithm, not an encryption algorithm by itself.
		* Each side has a private secret value and sends a related public value.
		* Both sides can independently calculate the same shared secret.
		* An eavesdropper sees the public values but should not be able to derive the shared secret efficiently.

	That shared secret can then be used to encrypt the actual messages.

9. RSA

	RSA is another public-key cryptography system, but it is not really a “successor” to Diffie–Hellman. They solve related but different problems.	

	RSA can be used for:
	    * Encrypting data using a public key
	    * Decrypting it using the matching private key
		* Creating and verifying digital signatures

	In practice, modern systems often use public-key cryptography to establish or protect a shared symmetric key, then use fast symmetric encryption for the bulk data.

9. Linear Programming

	Linear programming is a way to maximize or minimize something while following a set of constraints.

	The simplex algorithm is a classic method for solving linear-programming problems.

	Uses include:
	    * Scheduling
		* Logistics and routing
		* Resource allocation
		* Portfolio optimization
		* Manufacturing and supply-chain planning

