#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

// 오른쪽 왼쪽 아래 위 / 대각선들
const int dx[8] = { 1, -1, 0, 0, -1, -1, 1, 1};
const int dy[8] = { 0, 0, 1, -1, -1, 1, -1, 1};


void dfs(int w, int h, vector<vector<int>>& map, vector<vector<bool>>& visit)
{
	// 들어온곳은 방문한다.
	visit[h][w] = true;

	// 이어진 땅들을 다 방문해본다.
	for (int i = 0; i < 8; ++i)
	{
		int x = w + dx[i];
		int y = h + dy[i];

		// 마이너스면 없는거
		if (y < 0 || x < 0)
			continue;

		if (map.size() <= y || map[y].size() <= x)
			continue;

		// 방문하지 않았으면서, 여기도 땅이면 연결되어 있는 것.
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
		
		vector<vector<int>> map(h, vector<int>(w, 0));		// 맵
		vector<vector<bool>> visit(h, vector<bool>(w, false));	// 방문 기록

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				int temp;
				cin >> temp;
				map[i][j] = temp;
			}
		}

		// 섬인지 체크.
		int island = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				// 1. 섬인데
				// 2. 아직 방문을 안한 곳이다?
				if (map[i][j] == 1 && visit[i][j] == false)
				{
					// 3. 그러면 섬 개수를 체크하고
					island++;
					// 4. 이어진 땅들을 dfs로 다 체크한다.
					dfs(j, i, map, visit);
				}
			}
		}
		
		cout << island << endl;

	}
}