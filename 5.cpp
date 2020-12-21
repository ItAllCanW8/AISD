#include <iostream>
#include <vector>
#include <string>
#include <queue>

const long long maxLength = 1000000000000;
const int maxWeight = 1000000;
const int maxCounter = 100001;

struct Node 
{
	int num;

	long long length;

	bool operator<(const Node& other) const 
	{
		return length > other.length;
	}
};

std::priority_queue<Node> lengths;
std::vector<std::vector<std::pair<int, int>>> graph;
long long minLength[maxCounter];
bool check[maxCounter];

int main() 
{
	int N, M;
	std::cin >> N >> M;

	std::vector<std::pair<int, int>> t;

	for (int i = 0; i <= N; i++) 
	{
		graph.push_back(t);

		minLength[i] = maxLength;

		check[i] = false;
	}

	for (int i = 0; i < M; i++) 
	{
		int n1, n2, C;

		std::cin >> n1 >> n2 >> C;

		graph[n1].push_back(std::pair<int, int>(n2, C));
		graph[n2].push_back(std::pair<int, int>(n1, C));
	}

	int start, finish;
	std::cin >> start >> finish;

	lengths.push(Node{ start, 0 });
	minLength[start] = 0;

	for (int i = 0; i < N; i++) 
	{
		Node temp;

		while (true) 
		{
			temp = lengths.top();

			lengths.pop();

			if (check[temp.num]) 
				continue;
			check[temp.num] = true;

			break;
		}

		for (int j = 0; j < (int)graph[temp.num].size(); j++) 
		{
			long long check = temp.length + graph[temp.num][j].second;

			if (minLength[graph[temp.num][j].first] > check) 
			{
				minLength[graph[temp.num][j].first] = check;

				lengths.push(Node{ graph[temp.num][j].first, check });
			}
		}
	}

	std::cout << minLength[finish];

	return 0;
}