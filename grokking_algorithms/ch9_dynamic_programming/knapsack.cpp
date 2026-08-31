#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using ItemId = std::size_t;
using Price = int;
using Weight = int;

struct Item
{
	std::string name{};
	Price price{};
	Weight weight{};
};

const std::vector items{
	Item {"Guitar", 1500, 1},
	Item {"Stereo", 3000, 4},
	Item {"Laptop", 2000, 3}
};

const int maxWeight{ 4 };

// Optimized space: Use the fact that to build the next row, you only need the previous
// one.
int knapsack(const std::vector<Item>& items, int maxWeight)
{
	const std::size_t n{ items.size() };
	std::vector<Price> bestPrice(maxWeight + 1);

	for (const auto& item : items)
	{
		// Loop backwards so that you can look at the "previous row's" value before overwriting it with the current
		for (Weight capacity = maxWeight; capacity >= item.weight; --capacity)
		{
			const Price withoutItem = bestPrice[capacity];
			const Price withItem = item.price + bestPrice[capacity - item.weight];
			bestPrice[capacity] = std::max(withoutItem, withItem);
		}
	}

	for (const auto value : bestPrice)
		std::cout << std::setw(5) << value << ' ';
	std::cout << '\n';


	return 0;
}


// Get the best solution for the subproblem of a reduced item list and space,
// gradually adding one more item until getting the final solution
int knapsack2D(const std::vector<Item>& items, int maxWeight)
{
	const std::size_t n{ items.size() };
	std::vector<std::vector<Price>> bestPrice(n + 1, std::vector<Price>(maxWeight + 1));

	for (std::size_t i{ 1 }; i <= n; ++i)
	{
		const auto& item = items[i - 1];

		for (std::size_t capacity{ 1 }; capacity <= maxWeight; ++capacity)
		{
			const Price withoutItem = bestPrice[i - 1][capacity];

			if (item.weight > capacity)
			{
				bestPrice[i][capacity] = withoutItem;
				continue;
			}

			const Price withItem = item.price + bestPrice[i - 1][capacity - item.weight];

			bestPrice[i][capacity] = std::max(withoutItem, withItem);

		}
	}

	for (const auto& row : bestPrice)
	{
		for (const auto value : row)
			std::cout << std::setw(5) << value << ' ';
		std::cout << '\n';
	}

	return 0;
}