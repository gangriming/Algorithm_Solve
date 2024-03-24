#include <iostream>
#include <vector>
#include <queue>
#include <iomanip> // setw�� ����ϱ� ���� �ʿ���
#include <string>

using namespace std;

int dx[4] = { -1, -1, 1, 1 };
int dy[4] = { -1, 1, -1, 1 };

pair<int, int> dir_check(int curx, int cury, int size, int dir, int spd) {
    // dir 1~8 ��, ��, ��, ��, ��, ��, ��, ��
    int nx = curx, ny = cury; // ���ο� ��ġ�� ������ ����
    switch (dir) {
    case 1: // ��
        nx = (curx - spd) % size;
        break;
    case 2: // ��
        nx = (curx - spd) % size;
        ny = (cury - spd) % size;
        break;
    case 3: // ��
        ny = (cury - spd) % size;
        break;
    case 4: // ��
        nx = (curx + spd) % size;
        ny = (cury - spd) % size;
        break;
    case 5: // ��
        nx = (curx + spd) % size;
        break;
    case 6: // ��
        nx = (curx + spd) % size;
        ny = (cury + spd) % size;
        break;
    case 7: // ��
        ny = (cury + spd) % size;
        break;
    case 8: // ��
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

	// �� ���� �ִ� �ʺ� ������ ���͸� �ʱ�ȭ�մϴ�.
	vector<int> maxWidths(v[0].size(), 0);

	// ��� ��Ҹ� ��ȸ�ϸ鼭 �� ���� �ִ� �ʺ� ����մϴ�.
	for (const auto& row : v) {
		for (size_t j = 0; j < row.size(); ++j) {
			int length = to_string(row[j]).length();
			maxWidths[j] = max(maxWidths[j], length);
		}
	}

	// ������ �ʺ� ���缭 �迭�� ���� ����մϴ�.
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
				cout << "�� ";
			else
				cout << "�� ";
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

	// ������ ���� ǥ������.. pair�� �ѱ� �� �迭�� �ѱ�.
	vector<vector<bool>> cloud(n, vector<bool>(n, false));

	// �ʱ� ����
	cloud[n - 1][0] = true;
	cloud[n - 1][1] = true;
	cloud[n - 2][0] = true;
	cloud[n - 2][1] = true;
	

	while (m--)
	{
		/*
		1. ��� ������ di �������� siĭ �̵��Ѵ�.
		2. �� �������� �� ���� ������ �ִ� ĭ�� �ٱ��Ͽ� ����� ���� ���� 1 �����Ѵ�.
		3. ������ ��� �������.
		4. 2���� ���� ������ ĭ (r, c)�� ��������� ������ �����Ѵ�. ��������� ������ ����ϸ�, �밢�� �������� �Ÿ��� 1�� ĭ�� ���� �ִ� �ٱ����� ����ŭ (r, c)�� �ִ� �ٱ����� ���� ���� �����Ѵ�.
			�̶��� �̵��� �ٸ��� ��踦 �Ѿ�� ĭ�� �밢�� �������� �Ÿ��� 1�� ĭ�� �ƴϴ�.
			���� ���, (N, 2)���� ������ �밢�� ĭ�� (N-1, 1), (N-1, 3)�̰�, (N, N)���� ������ �밢�� ĭ�� (N-1, N-1)���̴�.
		5. �ٱ��Ͽ� ����� ���� ���� 2 �̻��� ��� ĭ�� ������ �����, ���� ���� 2 �پ���. �̶� ������ ����� ĭ�� 3���� ������ ����� ĭ�� �ƴϾ�� �Ѵ�.
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

			// �밢�� üũ
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
					cloud[i][j] = true;	// ���� ����
					v[i][j] -= 2;
				}
				else if (cloud[i][j] == true)
				{
					cloud[i][j] = false;	// ������ �ִ����� ������ �ȴ´�.
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