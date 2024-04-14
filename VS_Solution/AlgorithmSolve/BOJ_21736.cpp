#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m, 'O'));
	vector<vector<bool>> visit(n, vector<bool>(m, false));

	pair<int, int> pos;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			if(v[i][j] == 'I')
				pos = make_pair(i, j);
		}
	}

	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };

	// queue
	queue<pair<int, int>> q;
	q.push(pos);
	visit[pos.first][pos.second] = true;
	int meet = 0;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (v[cur.first][cur.second] == 'P')
			meet++;

		for (int i = 0; i < 4; ++i)
		{
			auto new_y = cur.first + dy[i];
			auto new_x = cur.second + dx[i];

			if (new_x >= 0 && new_x < m &&
				new_y >= 0 && new_y < n)
			{
				if (visit[new_y][new_x] == false && (v[new_y][new_x] == 'O' || v[new_y][new_x] == 'P'))
				{
					q.push(make_pair(new_y, new_x));
					visit[new_y][new_x] = true;
				}
			}
		}
	}

	if (meet == 0)
		cout << "TT" << endl;
	else
		cout << meet << endl;

}
