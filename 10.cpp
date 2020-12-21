#include <vector>
#include <iostream>
#include <string>

struct node
{
	int next[26];

	node()
	{
		for (int i = 0; i < 26; i++) 
			next[i] = 0;
	}
};

int main()
{
	std::string S;
	std::cin >> S;

	std::vector<node> trie(1);

	int length = S.length(), pos;

	node temp;

	for (int i = 0; i < length; i++)
	{
		pos = 0;

		for (int j = i; j < length; j++)
		{
			char ch = S[j] - 'a';

			if (trie[pos].next[ch] == 0)
			{
				trie[pos].next[ch] = trie.size();

				trie.push_back(temp);
			}
			pos = trie[pos].next[ch];
		}
	}

	std::cout << trie.size() - 1;

	return 0;
}