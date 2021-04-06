#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m = 0;
	cin >> n >> m;

	set<string> s;

	for (int i = 0; i < n; ++i)
	{
		string temp;
		cin >> temp;
		s.insert(temp);
	}

	set<string> s2;
	for (int i = 0; i < m; ++i)
	{
		string temp;
		cin >> temp;
		auto p = s.insert(temp);
		if (!p.second)	// 중복이면
		{
			s2.insert(temp);
		}
	}

	cout << s2.size() << endl;
	for (const auto& value : s2)
		cout << value << endl;
}