#include <iostream>

int main()
{
	std::string x;

	std::cin >> x;

	char lastNum = x[x.length() - 1];

	if (lastNum == '0')
		std::cout << "NO";
	else
		std::cout << lastNum;

	return 0;
}