#include <iostream>
#include <vector>
#include <map>
#include <queue>

struct coordinates 
{
	int x;
	int y;

	bool operator< (const coordinates& other) const 
	{
		if (x != other.x)
			return x < other.x;

		return y < other.y;
	}
};

std::map<coordinates, std::vector<coordinates>> movesGraph;
const int tableSize = 102;
bool isPossible[tableSize][tableSize];

bool isVisited[tableSize][tableSize];
int numOfMoves[tableSize][tableSize];

int rowsNum, columnsNum;

void addPossible(coordinates square) 
{
	std::vector<coordinates> possibleMoves;
	isPossible[square.x][square.y] = true;

	for (int i = -2; i < 3; i++)
		for (int j = -2; j < 3; j++) 
		{
			if (i == 0 || j == 0 || (abs(i) == 2 && abs(j) == 2)
				|| (abs(i) == 1 && abs(j) == 1)) 
				continue;
			if (square.x + j <= rowsNum && 1 <= square.x + j
				&& square.y + i <= columnsNum && 1 <= square.y + i)
				possibleMoves.push_back(coordinates{ square.x + j, square.y + i });
		}

	movesGraph.insert(std::pair<coordinates, std::vector<coordinates>>(square, possibleMoves));

	for (int i = 0; i < (int)possibleMoves.size(); i++)
	{
		if (!isPossible[possibleMoves[i].x][possibleMoves[i].y])
			addPossible(possibleMoves[i]);
	}
}

void foo(coordinates square) 
{
	isVisited[square.x][square.y] = true;

	std::queue<coordinates> moves;
	moves.push(square);

	while (!moves.empty()) 
	{
		coordinates from = moves.front();
		moves.pop();

		std::vector<coordinates> c = movesGraph[from];

		for (int i = 0; i < c.size(); i++) 
		{
			coordinates to = c[i];

			if (!isVisited[to.x][to.y])
			{
				isVisited[to.x][to.y] = true;
				moves.push(to);
				numOfMoves[to.x][to.y] = numOfMoves[from.x][from.y] + 1;
			}
		}
	}
}

int main() 
{
	std::cin >> rowsNum >> columnsNum;

	int lastRow, lastColumn;
	std::cin >> lastRow >> lastColumn;

	for (int i = 0; i < tableSize; i++)
		for (int j = 0; j < tableSize; j++) 
		{
			isPossible[i][j] = false;
			isVisited[i][j] = false;
			numOfMoves[i][j] = 0;
		}

	coordinates firstSquare = { 1, 1 };
	addPossible(firstSquare);

	if (!isPossible[lastRow][lastColumn])
	{
		std::cout << "NEVAR";

		return 0;
	}

	foo(firstSquare);
	std::cout << numOfMoves[lastRow][lastColumn];

	return 0;
}
