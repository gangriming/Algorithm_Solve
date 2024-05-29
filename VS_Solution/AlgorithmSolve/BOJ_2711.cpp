#include <iostream>
#include <string>

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
		int idx;
		string temp;
		cin >> idx >> temp;

		string answer = temp.substr(0, idx - 1) + temp.substr(idx, temp.length());

		cout << answer << "\n";
	}
}