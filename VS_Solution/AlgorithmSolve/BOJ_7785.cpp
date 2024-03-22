#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
	//unordered_set<string,

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n;
	cin >> n;

	set<string, greater<>> s;

	for (int i = 0; i < n; ++i)
	{
		string name, control;
		cin >> name >> control;

		if (control == "enter")
			s.insert(name);
		else
			s.erase(name);
	}

	for (auto value : s)
	{
		cout << value << "\n";
	}
}