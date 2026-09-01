#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>

using Rating = int;
using Duration = double;

struct Attraction
{
	std::string name{};
	Duration duration{};
	Rating rating{};
};

const std::vector attractions{
	Attraction { "Westminister Abbey"	, 0.5, 7},
	Attraction { "Globe Theater"		, 0.5, 6},
	Attraction {"National Gallery"		,   1, 9},
	Attraction { "British Museum"		,   2, 9},
	Attraction { "St. Paul's Cathedral"	, 0.5, 8}
};


constexpr Duration totalTime = 2;

// This is maximizing for total rating

// Solve the subproblem of best rating for a given smaller amount of time and reduced options.
// Increase the amount of time until it matches the total, and similarly use these results to calculate best solution with one by one more item.
int bestTravelingItinerary(const std::vector<Attraction> attractions, Duration totalTime)
{
	Duration minDuration = std::numeric_limits<double>::max(); // start at smallest time unit

	for (const auto& a : attractions)
		if (a.duration < minDuration) minDuration = a.duration;

	// truncated - for this case it's fine as durations increase in intervals of the smallest (0.5hrs), 
	// otherwise may have to do duration in minutes and intervals are 1 minute
	const int intervals{ static_cast<int>(totalTime / minDuration) }; 
	const std::size_t attractionCount{ attractions.size() };

	std::vector<std::vector<Rating>> bestRating(attractionCount + 1, std::vector<Rating>(intervals + 1));

	// Compares best rating so far vs (current attraction rating + best with remaining time)
	for (std::size_t i{ 1 }; i <= attractionCount; ++i)
	{
		const auto& attraction{ attractions[i - 1] };
		const std::size_t normalizedDuration{ static_cast<std::size_t>(attraction.duration / minDuration) }; // Amount of intervals it takes
		for (std::size_t interval{ 1 }; interval <= intervals; ++interval)
		{
			const Rating prevBest{ bestRating[i - 1][interval] };
			if (normalizedDuration > interval)
			{
				bestRating[i][interval] = prevBest;
				continue;
			}
			bestRating[i][interval] = std::max(prevBest, attraction.rating + bestRating[i - 1][interval - normalizedDuration]);
		}
	}

	// Display results - best one is last bottom left one
	for (const auto& row : bestRating)
	{
		for (const auto& rating : row)
		{
			std::cout << std::setw(3) << rating;
		}
		std::cout << '\n';
	}

	return 0;
}
