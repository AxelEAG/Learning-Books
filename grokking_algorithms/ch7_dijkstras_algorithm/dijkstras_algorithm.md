Dijkstra's algorithm is used to find the fastest path in a weighted graph.

Weighted graph - graph with edges that have weights associated to them, which
affect the way they are traversed.

Cycles - when nodes have edges that make them traverse them back to themselves.

Djikstra's algorithm only works with directed acyclic graphs (DAGs).


Algorithm:
	1. Find the cheapest node. 
	2. Update the costs of the neighbors of this node.
	3. Repeat until you've done this for every node in the graph.
	4. Calculate the final path.


Notes:
Bellman-Ford algorithm for graphs with negative weight edges
