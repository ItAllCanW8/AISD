#include <iostream>

bool sameChars(std::string S) 
{    
	for (int i = 0; i < S.length(); i++)
	{
		if (S[i] != S[0])
			return false;
	}

	return true;
}

bool isPal(std::string S) 
{      
	for (int i = 0; i < S.length() / 2; i++)
	{
		if (S[i] != S[S.length() - i - 1])
			return false;
	}

	return true;
}

int main() {
	std::string S;
	std::cin >> S;

	if (sameChars(S)) 
		std::cout << -1;

	else 
	{
		if (!isPal(S))  
			std::cout << S.length();

		else 
		{
			if (S[0] < S[1]) 
				std::cout << S.substr(0, S.length() - 1).length();
			else 
				std::cout << S.substr(1, S.length()).length();
		}
	}

	return 0;
}