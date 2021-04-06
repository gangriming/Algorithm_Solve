#include <iostream>
#include <queue>
using namespace std;


int main()
{
	const int cx[4] = { 1, -1, 0, 0 };
	const int cy[4] = { 0, 0, 1, -1 };

	char map[101][101] = { ' ', };
	bool visit[101][101] = { false, };

	int n, m = 0;	// n ���� , m ����
	cin >> n >> m;

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
			cin >> map[i][j];
	}

	queue<pair<int, int>> q;
	int score[2] = { 0, };

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			int count = 0;
			char search = map[i][j];	// Ž�� ���.

			if (!visit[i][j])
			{
				q.push(make_pair(i, j));	// <y, x>
				visit[i][j] = true;

				while (q.size())
				{
					pair<int, int> p = q.front();
					q.pop();
					count++;

					for (int k = 0; k < 4; ++k)
					{
						int nx = cx[k] + p.second;
						int ny = cy[k] + p.first;

						if (nx > n || nx <= 0
							|| ny > m || ny <= 0)
							continue;	// ���� �����

						if (!visit[ny][nx] && map[ny][nx] == search)
						{
							q.push(make_pair(ny, nx));	// <y, x>
							visit[ny][nx] = true;
						}
					}
				}
			}
			// �����ֱ�.
			if (search == 'W')
				score[0] += count * count;
			else
				score[1] += count * count;
		}
	}

	cout << score[0] << " " << score[1] << endl;
}