#include <array>
#include <vector>
#include <string_view>
#include <string>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>

#include<queue>
#include<numeric>

constexpr int SIZE = 64;

using Features = std::array<int, SIZE>;

struct Sample
{
	Features pixels{};
	int label{};
};

struct TestSample : Sample
{
	int predictedLabel{};
};


std::vector<TestSample> KNearestNeighbors(const std::vector<Sample>& trainingData, const std::vector<Sample>& testingData, std::size_t K)
{
	if (trainingData.size() < K)
		return {}; // Not enough samples to do KNN

	std::vector<TestSample> predictedData{};
	predictedData.reserve(testingData.size());

	for (std::size_t i{ 0 }; i < testingData.size(); ++i)
	{
		TestSample testSample{ testingData[i].pixels, testingData[i].label };

		// max heap to get the k smallest distances
		std::priority_queue<std::pair<int, int>> smallestSamples{}; // [distance, label]
		for (std::size_t j{ 0 }; j < K; ++j) {
			const Sample& sample = trainingData[j];
			smallestSamples.push({ getDistance(testSample, sample), sample.label });
		}

		for (std::size_t j{ K }; j < trainingData.size(); ++j)
		{
			const Sample& sample = trainingData[j];
			const int sampleDistance = getDistance(testSample, sample);
			const auto [dis, _] = smallestSamples.top();

			if (sampleDistance < dis) {
				smallestSamples.pop();
				smallestSamples.push({ sampleDistance, sample.label });
			}
		}

		// the label that appears the most is the one the testSample will be classified as

		std::array<int, 10> frequency{};
		int bestLabel{ 0 };
		for (std::size_t j{ 0 }; j < K; ++j)
		{
			const auto [_, label] = smallestSamples.top();
			smallestSamples.pop();

			++frequency[label];
			if (frequency[label] > frequency[bestLabel])
				bestLabel = label;
		}

		testSample.predictedLabel = bestLabel;
		predictedData.emplace_back(testSample);
	}

	return predictedData;
}