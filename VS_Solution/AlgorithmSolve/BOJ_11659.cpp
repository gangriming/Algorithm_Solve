#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tc;
	cin >> n >> tc;

	vector<long> v(n+1, 0);
	for(int i = 1 ; i <= n; ++i)
	{
		int temp;
		cin >> temp;

		v[i] = temp + v[i - 1];
	}

	while (tc--)
	{
		int i, j;
		cin >> i >> j;

		cout << v[j] - v[i - 1] << "\n";
	}
}