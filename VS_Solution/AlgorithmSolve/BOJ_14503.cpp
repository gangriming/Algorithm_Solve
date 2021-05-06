#include <iostream>
#include <vector>

using namespace std;

struct info
{
	int state = 0;
	bool visit = false;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int height, width = 0;
	cin >> height >> width;

	vector<vector<info>> map(height, vector<info>(width, info()));

	int r, c, d;
	cin >> r >> c >> d;
	// r = 로봇 청소기의 위부터의 위치
	// c = 왼쪽부터의 위치
	// d = 북 동 남 서 순서 0 1 2 3

	// 계산이 쉽게 반시계로 바꿔준다.
	if (d == 1)
		d = 3;
	else if (d == 3)
		d = 1;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			int temp;
			cin >> temp;
			map[i][j].state = temp;
		}
	}

	int clean = 0;
	bool logic = true;

	while (logic)
	{
		// 1. 현재 위치를 청소한다.
		if (map[r][c].state == 0 && !map[r][c].visit)
		{
			map[r][c].visit = true;
			clean++;
		}

		/*
		// Debug
		cout << "==============" << endl;
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				if (i == r && j == c)
					cout << "* ";
				else if(map[i][j].visit)
					cout << "* ";
				else
					cout << map[i][j].state << " ";
			}
			cout << endl;
		}
		cout << "==============" << endl << endl;
		*/

		// 초기 위치는 d, dir은 변환하는 방향
		int Dir = d;
		bool DirChange = false;

		// 2. 현재 위치에서 현재 방향을 기준으로 왼쪽부터 탐사.
		for (int i = 0; i < 4; ++i)
		{
			Dir = (d + 1) % 4;
			switch (Dir)
			{
			case 0:	// 북
				if (r - 1 >= 0)
				{
					// a
					if (map[r - 1][c].state == 0 && !map[r - 1][c].visit)
					{
						r -= 1;
						d = Dir;	// 전진, 회전
						DirChange = true;
					}
					else
						d = Dir;	// b
				}
				break;
			case 1:	// 서
				if (c - 1 >= 0)
				{
					// a
					if (map[r][c - 1].state == 0 && !map[r][c - 1].visit)
					{
						c -= 1;
						d = Dir;	// 전진, 회전
						DirChange = true;
					}
					else
						d = Dir;	// b
				}
				break;
			case 2:	// 남
				if (r + 1 < height)
				{
					// a
					if (map[r + 1][c].state == 0 && !map[r + 1][c].visit)
					{
						r += 1;
						d = Dir;	// 전진, 회전
						DirChange = true;
					}
					else
						d = Dir;	// b
				}
				break;
			case 3:	// 동
				if (c + 1 < width)
				{
					// a
					if (map[r][c + 1].state == 0 && !map[r][c + 1].visit)
					{
						c += 1;
						d = Dir;	// 전진, 회전
						DirChange = true;
					}
					else
						d = Dir;	// b
				}
				break;
			}
			
			if (DirChange)
				break;
		}

		
		if (!DirChange)
		{
			// c
			// d는 else부분.
			switch (d)
			{
			case 0:
				if (r + 1 < height && map[r+1][c].state == 0)
					r += 1;
				else
					logic = false;
				break;
			case 1:
				if (c + 1 < width && map[r][c + 1].state == 0)
					c += 1;
				else
					logic = false;
				break;
			case 2:
				if (r - 1 >= 0 && map[r - 1][c].state == 0)
					r -= 1;
				else
					logic = false;
				break;
			case 3 :
				if (c - 1 >= 0 && map[r][c - 1].state == 0)
					c -= 1;
				else
					logic = false;
				break;
			}
		}
	}

	cout << clean << endl;
}