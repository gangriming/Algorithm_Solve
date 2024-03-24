#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // setw를 사용하기 위해 필요함
#include <string>

using namespace std;

int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, -1, 1 };

pair<int, int> dir_check(int curx, int cury, int size, int dir, int spd) {
    // dir 1~8 ←, ↖, ↑, ↗, →, ↘, ↓, ↙
    int nx = curx, ny = cury; // 새로운 위치를 저장할 변수
    switch (dir) {
    case 1: // ←
        nx = (curx - spd) % size;
        break;
    case 2: // ↖
        nx = (curx - spd) % size;
        ny = (cury - spd) % size;
        break;
    case 3: // ↑
        ny = (cury - spd) % size;
        break;
    case 4: // ↗
        nx = (curx + spd) % size;
        ny = (cury - spd) % size;
        break;
    case 5: // →
        nx = (curx + spd) % size;
        break;
    case 6: // ↘
        nx = (curx + spd) % size;
        ny = (cury + spd) % size;
        break;
    case 7: // ↓
        ny = (cury + spd) % size;
        break;
    case 8: // ↙
        nx = (curx - spd) % size;
        ny = (cury + spd) % size;
        break;
    }

    if (nx < 0) nx += size;
    if (ny < 0) ny += size;
    nx %= size;
    ny %= size;

    return make_pair(nx, ny);
}


void debug(vector<vector<int>> v) {
	cout << "==========================\n\n";

	// 각 열의 최대 너비를 저장할 벡터를 초기화합니다.
	vector<int> maxWidths(v[0].size(), 0);

	// 모든 요소를 순회하면서 각 열의 최대 너비를 계산합니다.
	for (const auto& row : v) {
		for (size_t j = 0; j < row.size(); ++j) {
			int length = to_string(row[j]).length();
			maxWidths[j] = max(maxWidths[j], length);
		}
	}

	// 설정된 너비에 맞춰서 배열의 값을 출력합니다.
	for (const auto& row : v) {
		for (size_t j = 0; j < row.size(); ++j) {
			cout << setw(maxWidths[j] + 1) << row[j];
		}
		cout << "\n";
	}
}

void debugcloud(vector<vector<bool>> v) {
	cout << "-------------------- - n\n";

	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[0].size(); ++j)
		{
			if (v[i][j])
				cout << "■ ";
			else
				cout << "□ ";
		}
		cout << "\n";
	}

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}

	// 구름을 뭘로 표기하지.. pair로 둘까 새 배열을 둘까.
	vector<vector<bool>> cloud(n, vector<bool>(n, false));

	// 초기 구름
	cloud[n - 1][0] = true;
	cloud[n - 1][1] = true;
	cloud[n - 2][0] = true;
	cloud[n - 2][1] = true;
	

	while (m--)
	{
		/*
		1. 모든 구름이 di 방향으로 si칸 이동한다.
		2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다.
		3. 구름이 모두 사라진다.
		4. 2에서 물이 증가한 칸 (r, c)에 물복사버그 마법을 시전한다. 물복사버그 마법을 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니의 수만큼 (r, c)에 있는 바구니의 물이 양이 증가한다.
			이때는 이동과 다르게 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
			예를 들어, (N, 2)에서 인접한 대각선 칸은 (N-1, 1), (N-1, 3)이고, (N, N)에서 인접한 대각선 칸은 (N-1, N-1)뿐이다.
		5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
		*/

		int dir, spd;
		cin >> dir >> spd;

		queue<pair<int, int>> raindrop;

		//1, 2
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (cloud[i][j] == true)
				{
					auto pos = dir_check(j, i, n, dir, spd);
					v[pos.second][pos.first]++;
					cloud[i][j] = false;
					raindrop.push(pos);
				}
			}
		}

		// 4
		while (!raindrop.empty())
		{
			auto pos = raindrop.front();
			raindrop.pop();
			cloud[pos.second][pos.first] = true;

			// 대각선 체크
			int cnt = 0;
			for (int i = 0; i < 4; ++i) {
				int nx = pos.first + dx[i];
				int ny = pos.second + dy[i];

				if (nx >= 0 && nx < n 
					&& ny >= 0 && ny < n
					&& v[ny][nx] > 0)
					cnt++;
			}
			v[pos.second][pos.first] += cnt;
		}

		// 3, 5
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (cloud[i][j] != true && v[i][j] >= 2)
				{
					cloud[i][j] = true;	// 구름 생성
					v[i][j] -= 2;
				}
				else if (cloud[i][j] == true)
				{
					cloud[i][j] = false;	// 구름이 있던곳에 구름을 걷는다.
				}
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			answer += v[i][j];
	}

	cout << answer << endl;
}