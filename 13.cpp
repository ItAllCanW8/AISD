#include <iostream>
#include <algorithm>
#include <vector>

const int max = 10001;

std::vector<int> graph[max];
bool checked[max];
int nodesCount, linesCount;

void foo(int node) 
{
	checked[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
	{
		int nextNode = graph[node][i];

		if (!checked[nextNode])
			foo(nextNode);
	}
}

bool isConnected() 
{
	foo(1);

	for (int i = 2; i < nodesCount; i++)
		if (!checked[i])
			return false;

	return true;
}

int main() 
{
	std::cin >> nodesCount >> linesCount;

	for (int i = 0; i < linesCount; i++)
	{
		int firstNode, secondNode;
		std::cin >> firstNode >> secondNode;

		graph[firstNode].push_back(secondNode);
		graph[secondNode].push_back(firstNode);
	}

	if (isConnected())
		std::cout << linesCount - nodesCount + 1;
	else
		std::cout << -1;

	return 0;
}