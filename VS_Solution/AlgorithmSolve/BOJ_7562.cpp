#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int dx[8] = { -2,-2,-1,1,2,2,1,-1 };
int dy[8] = { -1,1,2,2,1,-1,-2,-2 };
int main()
{
	int tc;
	cin >> tc;


	while (tc--)
	{
		int l, cur_x, cur_y, goal_x, goal_y;
		cin >> l >> cur_x >> cur_y >> goal_x >> goal_y;

		vector<vector<int>> map(l, vector<int>(l, 0));	// ��
		vector<vector<bool>> visit(l, vector<bool>(l, false));	// üũ

		queue<pair<int, int>> q;
		q.push(make_pair(cur_x, cur_y));

		while(!q.empty())
		{ 
			// ���� ��ġ�� ������.
			auto pos = q.front();
			q.pop();

			// ������ ��ǥ���̸� ����Ѵ�.
			if (pos.first == goal_x && pos.second == goal_y)
			{
				cout << map[goal_x][goal_y] << endl;
				break;
			}


			for (int i = 0; i < 8; ++i)
			{
				auto x = pos.first + dx[i];
				auto y = pos.second + dy[i];

				if (x < 0 || y < 0)
					continue;

				if (x >= map.size() || y >= map.size())
					continue;

				if (visit[x][y] == false)
				{
					q.push(make_pair(x, y));
					visit[x][y] = true;	// �湮 ó��
					map[x][y] = map[pos.first][pos.second] + 1;	// ���� �̵�Ƚ�� +1 �� �����°��� ���ش�.
				}
			}
		}
	}
}