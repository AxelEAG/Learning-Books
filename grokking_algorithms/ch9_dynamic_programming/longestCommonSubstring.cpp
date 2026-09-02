#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <optional>

// Longest common substring: maximum substring (contiguous characters) in common between two strings.

// Solve the subproblem of smaller substrings, slowly adding more characters to one or the others.
// At any given point, the solution is either one more than the previous max if the current characters match, 
//		or 0 if they differ (sequence breaks).
std::string getLongestCommonSubstring(const std::string& s1, const std::string& s2)
{
	const std::size_t n{ s1.size() };
	const std::size_t m{ s2.size() };

	std::vector<std::vector<int>> longestSubstring(n + 1, std::vector<int>(m + 1));
	std::size_t bestStart = 0;
	std::size_t bestLength = 0;

	for (std::size_t i{ 1 }; i <= n; ++i)
	{
		const char c1 = s1[i - 1];
		for (std::size_t j{ 1 }; j <= m; ++j)
		{
			if (c1 == s2[j - 1])
			{
				auto& currLength = longestSubstring[i][j];
				currLength = longestSubstring[i - 1][j - 1] + 1;
				if (currLength > bestLength)
				{
					bestLength = currLength;
					bestStart = i - currLength;
				}
			}
		}
	}

	for (const auto& row : longestSubstring)
	{
		for (const auto& length : row)
			std::cout << std::setw(3) << length << ' ';

		std::cout << '\n';
	}

	std::string bestSubstring = s1.substr(bestStart, bestLength);

	std::cout << '\n' << "The longest common substring is: " << bestSubstring << '\n';
	return bestSubstring;
}
