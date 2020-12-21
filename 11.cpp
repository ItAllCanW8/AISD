#include <iostream>
#include <algorithm>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<std::vector<long long>> lengths;

long long counter;
long long sum = 0;
const long long module = 1e7 + 7;

int foo(int node, int root) 
{
	int countOfWays = 1;

	for (int i = 0; i < graph[node].size(); i++)
	{
		int nextNode = graph[node][i];

		if (nextNode != root) 
		{
			long long countNext = foo(nextNode, node);

			sum = (sum + (countNext * (counter - countNext)
				* lengths[node][nextNode] * 2)) % module;

			countOfWays += countNext;
		}
	}

	return countOfWays;
}

int main() 
{
	std::cin >> counter;

	graph.assign(counter + 1, std::vector<int>());
	lengths.assign(counter + 1, std::vector<long long>(counter + 1, 0));

	for (int i = 0; i < counter - 1; i++)
	{
		int firstNode, secondNode, length;

		std::cin >> firstNode >> secondNode >> length;

		graph[firstNode].push_back(secondNode);
		graph[secondNode].push_back(firstNode);
		lengths[firstNode][secondNode] = length;
	}

	foo(1, 0);

	std::cout << sum;

	return 0;
}