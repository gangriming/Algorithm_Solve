#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	set<string> s;
	int greeting = 0;
	
	while (n--)
	{
		string str;
		cin >> str;

		if (str == "ENTER")
			s.clear();
		else
		{
			if (s.find(str) == s.end())
			{
				s.insert(str);
				greeting++;
			}
		}
	}

	cout << greeting << endl;
}