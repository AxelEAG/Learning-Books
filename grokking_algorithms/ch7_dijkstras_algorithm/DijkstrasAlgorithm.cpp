#include <cstddef>
#include <vector>
#include <limits>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>

using NodeId = std::size_t;
using Distance = int;

struct Edge
{
	NodeId to{};
	Distance weight{};
};

std::vector<std::vector<Edge>> graph{
	// 0
	{{1, 7}, {2, 2}, {3, 9}},

	// 1
	{{0, 7}, {2, 3}, {4, 5}},

	// 2
	{{0, 2}, {1, 3}, {3, 4}, {4, 8}},

	// 3
	{{0, 9}, {2, 4}, {4, 3}, {5, 6}},

	// 4
	{{1, 5}, {2, 8}, {3, 3}, {5, 2}, {6, 7}},

	// 5
	{{3, 6}, {4, 2}, {6, 1}},

	// 6
	{{4, 7}, {5, 1}}
};


using QueueEntry = std::pair<Distance, NodeId>; // [distance, idx]
using MinHeap = std::priority_queue<QueueEntry, std::vector<QueueEntry>, std::greater<QueueEntry>>; // First compares distances, then indexes

constexpr int INF = std::numeric_limits<Distance>::max();


// Most efficient approach uses min heap instead
void dijkstrasAlgorithm(const std::vector<std::vector<Edge>>& graph)
{
	const std::size_t n{ graph.size() };

	const NodeId start = 0;
	const NodeId end = n - 1;

	std::vector<bool> visited(n, false);
	// Visited is not really needed. Currently used for 'lazy deletion' of nodes 
	// that get updated their best distance more than once.
	// However, can just compare distance[curr] != currDistance to ignore them too

	std::vector<NodeId> parent(n);
	std::vector<Distance> distance(n, INF);

	MinHeap queue{};
	queue.push({ 0, start });

	while (!queue.empty())
	{
		const auto [currDistance, curr] = queue.top();
		queue.pop();

		if (visited[curr] == true) // this would be distance[curr] != currDistance, all else would be deleted
			continue;

		visited[curr] = true;

		if (curr == end)
			break;

		for (const auto& [neighbor, weight] : graph[curr])
		{
			if (visited[neighbor]) continue; // Wasn't strictly needed anyways
			const int newDistance = currDistance + weight;
			if (newDistance < distance[neighbor])
			{
				distance[neighbor] = newDistance;
				parent[neighbor] = curr;
				queue.push({ newDistance, neighbor });
			}
		}
	}

	if (distance[end] == INF)
	{
		std::cout << "No path found \n";
		return;
	}

	std::vector<NodeId> path{};
	for (NodeId parentNode = end; parentNode != start; parentNode = parent[parentNode])
		path.emplace_back(parentNode);
	path.emplace_back(start);
	std::reverse(path.begin(), path.end());

	std::cout << "Path: ";
	for (auto node : path)
		std::cout << node << ' ';
	std::cout << '\n';

	return;
}

void dijkstrasAlgorithmSuboptimal(const std::vector<std::vector<Edge>>& graph)
{
	const std::size_t n{ graph.size() };

	std::vector<bool> visited(n, false);
	std::vector<int> distance(n, INF);
	std::vector<std::size_t> parent(n);

	const std::size_t start = 0;
	const std::size_t end = n - 1;

	distance[start] = 0;

	auto next{ start };
	for (std::size_t curr{ start }; curr != end; curr = next)
	{
		const int currDistance = distance[curr];
		visited[curr] = true;

		for (const auto& [neighbor, weight] : graph[curr])
		{
			if (visited[neighbor]) continue;
			const int newDistance = currDistance + weight;
			if (newDistance < distance[neighbor])
			{
				distance[neighbor] = newDistance;
				parent[neighbor] = curr;
			}
		}

		next = n;
		int smallestDistance = INF;
		for (std::size_t i = 0; i < n; ++i)
		{
			if (!visited[i] && distance[i] < smallestDistance)
			{
				smallestDistance = distance[i];
				next = i;
			}
		}
		if (next == n) break;
	}

	if (distance[end] == INF)
	{
		std::cout << "No path found \n";
		return;
	}

	std::vector<std::size_t> path{};
	for (std::size_t parentNode = end; parentNode != start; parentNode = parent[parentNode])
		path.emplace_back(parentNode);
	path.emplace_back(start);
	std::reverse(path.begin(), path.end());

	std::cout << "Path: ";
	for (auto node : path)
		std::cout << node << ' ';
	std::cout << '\n';

	return;
}