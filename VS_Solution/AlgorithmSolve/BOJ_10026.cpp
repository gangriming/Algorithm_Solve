#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 오른쪽 왼쪽 아래 위
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<char>> v(n, vector<char>(n, ' '));
	vector<vector<bool>> b(n, vector<bool>(n, false));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char c;
			cin >> c;
			v[i][j] = c;
		}
	}


	// 1) 적녹색약 X
	queue<pair<int, int>> q;
	int section = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!b[i][j])
			{
				char search = v[i][j];
				b[i][j] = true;
				q.push(make_pair(i, j));
				section++;

				while (!q.empty())
				{
					auto p = q.front();
					q.pop();

					for (int k = 0; k < 4; ++k)
					{
						int ix = p.second+ dx[k];
						int iy = p.first + dy[k];

						if (ix >= 0 && ix < n
							&& iy >= 0 && iy < n)	// 맵 범위 안
						{
							if (!b[iy][ix] && v[iy][ix] == search)
							{
								// 방문하지 않은 것 중, 같은 색상
								q.push(make_pair(iy, ix));
								b[iy][ix] = true;
							}
						}
					}
				}

			}
		}
	}

	// 2) 적녹색약 O
	vector<vector<bool>> b2(n, vector<bool>(n, false));
	int section2 = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!b2[i][j])
			{
				char search = v[i][j];
				b2[i][j] = true;
				q.push(make_pair(i, j));
				section2++;

				int debug = 0;

				while (!q.empty())
				{
					auto p = q.front();
					q.pop();
					debug++;

					for (int k = 0; k < 4; ++k)
					{
						int ix = p.second + dx[k];
						int iy = p.first + dy[k];
						
						if (ix >= 0 && ix < n
							&& iy >= 0 && iy < n)	// 맵 범위 안
						{
							if (!b2[iy][ix])
							{
								if (search == 'B' && v[iy][ix] == search)
								{
									q.push(make_pair(iy, ix));
									b2[iy][ix] = true;
								}
								// Debug : B랑 R이 같이 잡혀서 값이 이상함. 조건을 더 세부화 하면 될 듯.
								// else if 를 2개 늘려서 해결 했지만, 코드 수를 줄일 수 없을까?
								else if(search == 'G' && v[iy][ix] == search)
								{
									q.push(make_pair(iy, ix));
									b2[iy][ix] = true;
								}
								else if (search == 'G' && v[iy][ix] == 'R')
								{
									q.push(make_pair(iy, ix));
									b2[iy][ix] = true;
								}
								else if (search == 'R' && v[iy][ix] == search)
								{
									q.push(make_pair(iy, ix));
									b2[iy][ix] = true;
								}
								else if (search == 'R' && v[iy][ix] == 'G')
								{
									q.push(make_pair(iy, ix));
									b2[iy][ix] = true;
								}
							}
						}	
					}
				}
			}
		}
	}

	cout << section << ' ' << section2 << endl;

	
}