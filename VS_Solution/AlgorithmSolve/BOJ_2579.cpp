#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> v(n+1);

	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	if (n == 1)
	{
		cout << v[1] << endl;
		return 0;
	}

	vector<int> dp(n + 1);

	bool ispossible = true;

	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	if(n == 2)
	{
		cout << dp[2] << endl;
		return 0;
	}
		
	dp[3] = max(v[1], v[2]) + v[3];
	if (n == 3)
	{
		cout << dp[3] << endl;
		return 0;
	}


	for(int i = 4 ; i <= n ; ++i)
	{
		// 올라온 계단은, 밟았다는 뜻
		dp[i] = v[i] + max(dp[i - 2], dp[i - 3] + v[i - 1]);
	}

	cout << dp[n] << "\n";
}