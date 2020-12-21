#include <iostream>

int main() 
{
	int N;
	long max, prev = 0, num, sum = 0;

	std::cin >> N >> prev;

	max = prev;

	for (int i = 1; i < N; i++) 
	{
		std::cin >> num;

		if (num > max) 
		{
			sum += (num - max);
			max = num;
		}
		else
			if (num < prev)
				sum += (prev - num);

		prev = num;
	}

	std::cout << sum;

	return 0;
}