#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 트리 안써도 될듯
	int n, m;
	cin >> n;

	long temp;

	unordered_set<long> s;
	
	for(int i = 0 ; i < n ; ++i)
	{
		cin >> temp;
		s.insert(temp);
	}

	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> temp;
		if (s.find(temp) == s.end())
			cout << 0 << '\n';
		else
			cout << 1 << '\n';
	}
}