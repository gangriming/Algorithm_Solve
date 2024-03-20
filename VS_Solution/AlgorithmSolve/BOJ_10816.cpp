#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	unordered_map<long, int> m;

	for(int i = 0 ; i < n ; ++i)
	{ 
		long a;
		cin >> a;
		m[a]++;
	}

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i)
	{
		long a;
		cin >> a;
		cout << m[a] << " ";
	}
}