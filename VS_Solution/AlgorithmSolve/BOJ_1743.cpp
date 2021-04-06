#include <iostream>
#include <queue>

using namespace std;


int way[101][101] = { 0, };
bool visit[101][101] = { false, };

// ������ �Ʒ� ���� ��
const int cx[4] = { 1, 0, -1, 0 };
const int cy[4] = { 0, 1, 0, -1 };


int main()
{
	int width, height = 0;
	cin >> height >> width;

	int garbage = 0;
	cin >> garbage;

	for (int i = 0; i < garbage; ++i)
	{
		int x, y = 0;
		cin >> y >> x;		// �̰� �ٲ�Ἥ Ʋ�� ��

		way[y][x] = 1;
	}

	int maxGarbage = 0;
	queue<pair<int, int>> search;

	for (int i = 1; i <= height; ++i)
	{
		for (int j = 1; j <= width; ++j)
		{
			if (!visit[i][j] && way[i][j] == 1)
			{
				// bfs�� �¿��.
				search.push(make_pair(j, i));	// (x, y) ���̱⶧���� (j, i)
				visit[i][j] = true;
				int searchGarbage = 0;

				while (search.size())
				{
					pair<int, int> p = search.front();
					search.pop();
					visit[p.second][p.first] = true;
					searchGarbage++;

					for (int k = 0; k < 4; ++k)
					{
						int nx = p.first + cx[k];
						int ny = p.second + cy[k];

						if (ny > height || ny <= 0
							|| nx > width || nx <= 0)
							continue;

						if (!visit[ny][nx] &&
							way[ny][nx] == 1)
						{
							search.push(make_pair(nx, ny));
							visit[ny][nx] = true;
						}
					}
				}

				if (searchGarbage > maxGarbage)
					maxGarbage = searchGarbage;

			}
		}
	}

	cout << maxGarbage << endl;

}