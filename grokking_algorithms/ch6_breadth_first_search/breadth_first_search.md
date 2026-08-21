Graphs are a way to model how different things are connected to one another.
They are made of nodes (things) and edges (connections), where directly 
connected nodes are called neighbors.

Breadth first search - an algorithm for iterating through a graph by 'levels'.
To accomplish this, nodes must be added and processed from oldest to newest.
For this, a queue is best. 

A queue is a data structure that follows First In First Out (FIFO) principle.
Items get added to the list at the back, and are removed from the front, just
like a real life queue.

Common ways to represent graphs are:
	* Adjacency list: A key-value map of nodes to a list of connections
	* Adjacency matrix: for dense graphs, represent connections between nodes u and v in matrix[u][v]
	* Edge list: a list of connections between two nodes

In directed graphs, connections have a direction, while in undirected they don't.

Tree: special type of graph where connections never point back

Notes:
Check out
 - Fewest edits algorithm
 - Shortest path algorithm
 - Topological sort
