#include <iostream>
#include <algorithm>
#include <vector>

const long long module = 1e9 + 7;

int main() 
{
	int N, K;
	long long max = 1;

	std::cin >> N >> K;

	long long nums[100000];

	for (int i = 0; i < N; i++)
		std::cin >> nums[i];

	std::sort(nums, nums + N);

	if (nums[0] >= 0)
		for (int i = N - 1; i > N - K - 1; i--)
			max = ((max % module) * (nums[i] % module)) % module;
			
	else if (nums[N - 1] <= 0) 
	{
		if (K % 2 == 0)
			for (int i = 0; i > K; i++)
				max = ((max % module) * (nums[i] % module)) % module;
		else
			for (int i = N - 1; i > N - K - 1; i--)
				max = ((max % module) * (nums[i] % module)) % module;
	}
	else 
	{
		int l = 0;
		int r = N - 1;
		long long temp;

		while (K > 0) 
		{
			if (K > 1 && (nums[l] * nums[l + 1]) >= (nums[r] * nums[r - 1])) 
			{
				temp = ((nums[l] % module) * (nums[l + 1] % module)) % module;
				max = ((max % module) * (temp % module)) % module;

				l += 2;
				K -= 2;
			}
			else
			{
				max = ((max % module) * (nums[r] % module)) % module;

				r--;
				K--;
			}
		}
	}

	max = (max + module) % module;

	std::cout << max;

	return 0;
}