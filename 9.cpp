#include <iostream>
#include <vector>

int main() 
{
	std::string S;
	std::cin >> S;

	std::vector<int> chars(S.length() + 1);

	for (int i = 0; i < S.length(); i++)
		chars[i] = 0;

	int Q;
	std::cin >> Q;

	for (int i = 0; i < Q; i++) 
	{
		int L, R;
		std::cin >> L >> R;

		if (R < L) 
			std::swap(L, R);

		chars[L - 1]++;
		chars[R]--;
	}

	for (int i = 1; i < chars.size(); i++)
		chars[i] += chars[i - 1];

	for (int i = 0; i < S.length(); i++) 
	{
		if (chars[i] % 2 == 1)
			isupper(S[i]) ? S[i] = tolower(S[i]) : S[i] = toupper(S[i]);
	}

	std::cout << S;

	return 0;
}