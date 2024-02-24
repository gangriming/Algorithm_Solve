#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// ������ ���� �Ʒ� �� / �밢����
const int dx[8] = { 1, -1, 0, 0, -1, -1, 1, 1};
const int dy[8] = { 0, 0, 1, -1, -1, 1, -1, 1};


void dfs(int w, int h, vector<vector<int>>& map, vector<vector<bool>>& visit)
{
	// ���°��� �湮�Ѵ�.
	visit[h][w] = true;

	// �̾��� ������ �� �湮�غ���.
	for (int i = 0; i < 8; ++i)
	{
		int x = w + dx[i];
		int y = h + dy[i];

		// ���̳ʽ��� ���°�
		if (y < 0 || x < 0)
			continue;

		if (map.size() <= y || map[y].size() <= x)
			continue;

		// �湮���� �ʾ����鼭, ���⵵ ���̸� ����Ǿ� �ִ� ��.
		if (map[y][x] == 1 && visit[y][x] == false)
			dfs(x, y, map, visit);	
	}
}

int main()
{
	while (true)
	{
		int w, h;
		cin >> w >> h;

		if (w == 0 && h == 0)
			return 0;
		
		vector<vector<int>> map(h, vector<int>(w, 0));		// ��
		vector<vector<bool>> visit(h, vector<bool>(w, false));	// �湮 ���

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				int temp;
				cin >> temp;
				map[i][j] = temp;
			}
		}

		// ������ üũ.
		int island = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				// 1. ���ε�
				// 2. ���� �湮�� ���� ���̴�?
				if (map[i][j] == 1 && visit[i][j] == false)
				{
					// 3. �׷��� �� ������ üũ�ϰ�
					island++;
					// 4. �̾��� ������ dfs�� �� üũ�Ѵ�.
					dfs(j, i, map, visit);
				}
			}
		}
		
		cout << island << endl;

	}
}