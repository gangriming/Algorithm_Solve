#include <iostream>
#include <vector>
#include <algorithm>	

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n+1);
	vector<int> dp(n+1);
	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		int check = 0;
		for (int j = 1; j < i; ++j)
		{
			if (v[i] > v[j])	// 현재 체크하고 있는 값이, 이전 값들보다 크다면
				check = max(check, dp[j]);
		}
		dp[i] = check + 1;
		answer = max(answer, dp[i]);
	}

	cout << answer << "\n";
}