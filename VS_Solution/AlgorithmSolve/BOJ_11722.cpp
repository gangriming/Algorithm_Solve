#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> dp(n + 1);

	int answer = 0;

	for(int i = 1 ; i <= n; ++i)
	{ 
		cin >> v[i];
		int check = 0;
		for (int j = 1; j < i; ++j)
		{
			if (v[j] > v[i])	// 지금 들어온게, 전 값보다 감소했으면
			{
				check = max(check, dp[j]);
			}
		}
		dp[i] = check + 1;
		answer = max(answer, dp[i]);
	}
	cout << answer << endl;
}