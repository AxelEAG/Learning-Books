#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

int main()
{
    std::unordered_map<int, std::vector<int>> graph{
        {1, {2, 3, 5}},
        {2, {1, 4, 6}},
        {3, {1, 4, 7}},
        {4, {2, 3, 8}},
        {5, {1, 6}},
        {6, {2, 5, 8, 9}},
        {7, {3, 8}},
        {8, {4, 6, 7, 10}},
        {9, {6, 10}},
        {10, {8, 9}}
    };

    std::queue<int> queue;
    std::unordered_set<int> seen;

    queue.push(1);
    seen.insert(1);

    while (!queue.empty())
    {
        const int node = queue.front();
        queue.pop();

        std::cout << node << '\n';

        for (const int neighbor : graph.at(node))
        {
            if (seen.insert(neighbor).second)
                queue.push(neighbor);
        }
    }

    return 0;
}
