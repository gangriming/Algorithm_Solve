#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m = 0;

	cin >> n >> m;

	// 2차원 벡터 생성
	vector<vector<int>> mat(n, vector<int>(m, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int num = 0;
			cin >> num;

			mat[i][j] = num;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int num2 = 0;
			cin >> num2;

			mat[i][j] += num2;
		}
	}

	// 출력
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	return 0;
}