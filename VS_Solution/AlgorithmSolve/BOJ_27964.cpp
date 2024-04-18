#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	set<string> s;

	while (n--)
	{
		string str;
		cin >> str;

		if (str.size() < 6)
			continue;
		else // Cheese의 문자열 크기만큼은 되어야 검사할만 함.
		{
			int start = str.size() - 6;
			string check = str.substr(start, 6);

			if (check == "Cheese")
				s.insert(str);
		}
	}

	if (s.size() >= 4)
		cout << "yummy\n";
	else
		cout << "sad\n";
}