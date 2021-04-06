#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#pragma warning(disable:4996)
#define INF 99999999

using namespace std;

// 동 서 남 북 상 하
const int cx[6] = { 1, -1, 0, 0, 0, 0 };
const int cy[6] = { 0, 0, 1, -1, 0, 0 };
const int cz[6] = { 0, 0, 0, 0, -1, 1 };

struct info
{
	int cost = INF;
	bool visit = false;
	char block = ' ';
};

int main()
{
	while (1)
	{
		// L = 층 수 (Z)
		// R = 행 (Y)
		// C = 열 (X)
		int L, R, C = 0;
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0)	// 입력 끝
			break;

		info build[31][31][31];
		//char build[31][31][31];
		//bool visit[31][31][31];
		//int cost[31][31][31] = {9999999, };
		//
		//
		//memset(&visit, false, sizeof(bool) * 31 * 31 * 31);
		//memset(&cost, 10000000, sizeof(cost));

		tuple<int, int, int> start;
		tuple<int, int, int> escape;
		
		for (int z = 1; z <= L; ++z)
		{
			for (int y = 1; y <= R; ++y)
			{
				for (int x = 1; x <= C; ++x)
				{
					cin >> build[z][y][x].block;
					if (build[z][y][x].block == 'S')
						start = make_tuple(z, y, x);

					if(build[z][y][x].block == 'E')
						escape = make_tuple(z, y, x);
				}
			}
		}

		queue<tuple<int, int, int>> q;
		q.push(start);
		build[get<0>(start)][get<1>(start)][get<2>(start)].visit = true;
		build[get<0>(start)][get<1>(start)][get<2>(start)].cost = 0;

		while (q.size())
		{
			tuple<int, int, int> search = q.front();
			q.pop();

			for (int i = 0; i < 6; ++i)
			{
				int iZ = cz[i] + get<0>(search);
				int iY = cy[i] + get<1>(search);
				int iX = cx[i] + get<2>(search);

				if (iZ < 1 || iZ > L || iY < 1 || iY > R || iX < 1 || iX > C)
					continue;

				if (!build[iZ][iY][iX].visit &&
					build[iZ][iY][iX].block == '.' || build[iZ][iY][iX].block == 'E')
				{
					if (build[iZ][iY][iX].cost
						> build[get<0>(search)][get<1>(search)][get<2>(search)].cost + 1)
					{
						// 갱신.
						build[iZ][iY][iX].cost = build[get<0>(search)][get<1>(search)][get<2>(search)].cost + 1;
					}

					q.push(make_tuple(iZ, iY, iX));
					build[iZ][iY][iX].visit = true;		// 넣을때 visit처리해주는게 핵심이라고 한다.
				}
			}
		}

		// for debug
		//for (int z = 1; z <= L; ++z)
		//{
		//	for (int y = 1; y <= R; ++y)
		//	{
		//		for (int x = 1; x <= C; ++x)
		//		{
		//			if (build[z][y][x].cost == INF)
		//				cout << "X";
		//			else
		//				cout << build[z][y][x].cost;
		//		}
		//		cout << endl;
		//	}
		//	cout << endl << endl;
		//}
		if (build[get<0>(escape)][get<1>(escape)][get<2>(escape)].cost == INF)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " 
			<< build[get<0>(escape)][get<1>(escape)][get<2>(escape)].cost << " minute(s)." << endl;
	}
}