#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int note1;
		cin >> note1;
		
		unordered_set<int> s;
		while (note1--)
		{
			int m;
			cin >> m;
			s.emplace(m);
		}

		int note2;
		cin >> note2;
		while (note2--)
		{
			int m;
			cin >> m;

			if (s.find(m) == s.end())
				cout << "0\n";
			else
				cout << "1\n";
		}
	}
}