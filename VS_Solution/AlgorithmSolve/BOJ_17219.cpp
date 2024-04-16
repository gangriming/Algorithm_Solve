#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> mm;

	while (n--)
	{
		string str, pass;
		cin >> str >> pass;

		mm[str] = pass;
	}

	while (m--)
	{
		string str;
		cin >> str;

		cout << mm[str] << "\n";
	}

}