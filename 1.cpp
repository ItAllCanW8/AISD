#include <iostream>
#include <string>
#include <vector>

const int maxLength = 10001;

std::vector<int> graph[maxLength];

bool check[maxLength];

int quantity = 0;


void foo(int n) 
{
	check[n] = true;

	for (int i = 0; i < (int)graph[n].size(); i++)
	{
		int v = graph[n][i];

		if (!check[v])
			foo(v);
	}
}

int main() 
{
	int N, M;

	std::cin >> N >> M;

	for (int i = 0; i < M; i++) 
	{
		int n1, n2;
		std::cin >> n1 >> n2;

		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	for (int i = 1; i <= N; i++) 
	{
		if (!check[i]) 
		{
			foo(i);

			quantity++;
		}
	}

	std::cout << quantity - 1;

	return 0;
}