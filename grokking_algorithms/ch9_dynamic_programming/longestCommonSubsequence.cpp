#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <optional>
#include <algorithm>

// Longest common subsequence: maximum subsequence (non-contiguous characters) in common between two strings.

// Solve the subproblem of smaller subsequences, slowly adding more characters to one or the others.
// At any given point, the solution is either one more than the previous max if the current characters match, 
//		or the best seen so far (prev element or best with one less letter).
// Then, reconstruct the substring by walking from the end of the strings, towards the beginning,
//		following the longestSubsequence
std::string getLongestCommonSubsequence(const std::string& s1, const std::string& s2)
{
	const std::size_t n{ s1.size() };
	const std::size_t m{ s2.size() };

	std::vector<std::vector<int>> longestSubsequence(n + 1, std::vector<int>(m + 1));
	for (std::size_t i{ 1 }; i <= n; ++i)
	{
		const char c1 = s1[i - 1];
		for (std::size_t j{ 1 }; j <= m; ++j)
		{
			if (c1 == s2[j - 1])
				longestSubsequence[i][j] = longestSubsequence[i - 1][j - 1] + 1;
			else
				longestSubsequence[i][j] = std::max(longestSubsequence[i][j - 1], longestSubsequence[i - 1][j]);
		}
	}

	for (const auto& row : longestSubsequence)
	{
		for (const auto& length : row)
			std::cout << std::setw(3) << length << ' ';

		std::cout << '\n';
	}

	// Walk backwards to reconstruct it
	std::string bestSubsequence{};
	bestSubsequence.reserve(longestSubsequence[n][m]);
	int i = n;
	int j = m;
	while (i > 0 && j > 0)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			bestSubsequence += s1[i - 1];
			--i;
			--j;
		}
		else if (longestSubsequence[i - 1][j] >= longestSubsequence[i][j - 1])
			--i;
		else
			--j;
	}
	std::reverse(bestSubsequence.begin(), bestSubsequence.end());
	std::cout << '\n' << "The longest common subsequence is: " << bestSubsequence << '\n';
	return bestSubsequence;
}
