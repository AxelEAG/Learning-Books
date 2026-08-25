Greedy Strategy: At each step, pick the locally optimal solution (best next step).

This is an approximation strategy that can give the best solution, but not necessarily.

Approximation algorithms are judged by
	* how fast they are
	* how close they get to the optimal solution

P == NP Problem - asks whether every problem whose solution can be quickly verified 
	by a computer can also be quickly solved by a computer.
	* P (Polynomial time) - Represents problems that a computer can solve quickly and efficiently.
	* NP (Non-polynomial time) - Represents problems where the solution can be verified quickly, but finding it cannot.
	
Giveaways of when a problem might be NP-Complete:
	* Terrible runtime scaling
	* Involves combinations/permutations
	* Need to calculate every possible version (cannot breakdown into subproblems)
	* Requires sequences or sets and is hard to solve

Notes:
Traveling salesperson problem
