#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> check_pos(string str)
{
	pair<int, int> a;

	switch (str[0])
	{
	case 'A':
		a.first = 0; break;
	case 'B':
		a.first = 1; break;
	case 'C':
		a.first = 2; break;
	case 'D':
		a.first = 3; break;
	case 'E':
		a.first = 4; break;
	case 'F':
		a.first = 5; break;
	case 'G':
		a.first = 6; break;
	case 'H':
		a.first = 7; break;
	}

	a.second = ((int)(str[1] - '0')) - 1;

	return a;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string king, stone;
	cin >> king >> stone;

	int move;
	cin >> move;

	// first = 가로 // second = 세로
	auto king_pos = check_pos(king);
	auto stone_pos = check_pos(stone);

	//vector<vector<int>> v(8, vector<int>(8, 0));		// 왕이면 1, 돌이면 2

	//v[king_pos.second][king_pos.first] = 1;
	//v[stone_pos.second][stone_pos.first] = 2;

	while (move--)
	{
		string cmd;
		cin >> cmd;

		// 나갈경우는 제외
		auto temp_king = king_pos;

		if (cmd == "R")
		{
			if (temp_king.first + 1 > 7)
			{

			}
		}
		else if (cmd == "L")
		{

		}
		else if (cmd == "B")
		{

		}
		else if (cmd == "T")
		{

		}
		else if (cmd == "RT")
		{

		}
		else if (cmd == "LT")
		{

		}
		else if (cmd == "RB")
		{

		}
		else if (cmd == "LB")
		{

		}
	}
}