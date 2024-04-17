#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(vector<vector<bool>>& visit, vector<vector<int>>& v, int x, int y)
{
	visit[y][x] = true;

	for (int i = 0; i < 4; ++i)
	{
		int curx = x + dx[i];
		int cury = y + dy[i];

		if (curx >= 0 && curx < v[0].size()
			&& cury >= 0 && cury < v.size())
		{
			if (!visit[cury][curx] && v[cury][curx] > 0)
				dfs(visit, v, curx, cury);
		}
	}
}

int check_iceberg(vector<vector<int>>& v)
{
	vector<vector<bool>> visit(v.size(), vector<bool>(v[0].size(), false));

	int iceberg = 0;

	for (int a = 0; a < v.size(); ++a)
	{
		for (int b = 0; b < v[0].size(); ++b)
		{
			if (v[a][b] > 0 && !visit[a][b])
			{
				iceberg++;

				for (int i = 0; i < 4; ++i)
				{
					int curx = b + dx[i];
					int cury = a + dy[i];

					if (curx >= 0 && curx < v[0].size()
						&& cury >= 0 && cury < v.size())
					{
						if (!visit[cury][curx] && v[cury][curx] > 0)
							dfs(visit, v, curx, cury);
					}
				}
			}
		}
	}

	return iceberg;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> v[i][j];
	}

	// 최초 빙산의 덩어리도 체크
	auto init_ice = check_iceberg(v);
	if (init_ice >= 2)
	{
		// 2개 이상이었다면 그냥 빠져나감.
		cout << "0\n";
		return 0;
	}

	int years = 0;
	int ice = 0;

	while (true)
	{
		years++;
		
		queue<tuple<int, int, int>> q; // 녹을 빙하 x, y, 인접한 바다 개수

		// 빙산 녹이고
		for (int a = 0; a < v.size(); ++a)
		{
			for (int b = 0; b < v[0].size(); ++b)
			{
				if (v[a][b] > 0)
				{
					int near = 0;

					for (int i = 0; i < 4; ++i)
					{
						int curx = b + dx[i];
						int cury = a + dy[i];

						if (curx >= 0 && curx < v[0].size()
							&& cury >= 0 && cury < v.size())
						{
							if (v[cury][curx] <= 0)
								near++;
						}
					}
					
					if(near > 0)
						q.push(make_tuple(a, b, near));
				}
			}
		}

		while (!q.empty())
		{
			auto check = q.front();
			q.pop();

			v[get<0>(check)][get<1>(check)] -= get<2>(check);
		}

		// 덩어리 체크
		ice = check_iceberg(v);
		if (ice >= 2 || ice <= 0)
			break;
	}

	if (ice <= 0)
		cout << "0\n";
	else
		cout << years << "\n";

}