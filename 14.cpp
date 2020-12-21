#include <iostream>
#include <vector>

const int mod = 1e9 + 7;

std::vector<std::vector<long long>> mul(std::vector<std::vector<long long>> a, std::vector<std::vector<long long>> b) 
{
	int size = (int)a.size();

	std::vector<std::vector<long long>> c(size, std::vector<long long>(size, 0));

	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
				c[i][j] = (c[i][j] + a[i][k] * b[k][j] % mod) % mod;
		}
	}

	return c;
}

std::vector<std::vector<long long>> binPower(std::vector<std::vector<long long>> a, int k) 
{
	int size = (int)a.size();

	std::vector<std::vector<long long>> b(size, std::vector<long long>(size, 0));

	for (int i = 0; i < size; i++)
		b[i][i] = 1;

	while (k)
	{
		if (k % 2 == 1)
		{
			b = mul(b, a);
			k--;
		}
		else {
			a = mul(a, a);
			k /= 2;
		}
	}

	return b;
}

int main() 
{
	int N, M;
	std::cin >> N >> M;

	int U, V, L;
	std::cin >> U >> V >> L;

	std::vector<std::vector<long long>> inputMatrix(N, std::vector<long long>(N, 0));

	for (int i = 0; i < M; i++)
	{
		int A, B;
		std::cin >> A >> B;

		A--;
		B--;
		if (A == B)
			inputMatrix[A][B] += 2;
		else 
		{
			inputMatrix[A][B] += 1;
			inputMatrix[B][A] += 1;
		}
	}

	inputMatrix = binPower(inputMatrix, L);

	std::cout << inputMatrix[U - 1][V - 1];
}