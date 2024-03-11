#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m = 0;
	cin >> n >> m;

	unordered_map<int, string> map;
	unordered_map<string, int> map2;

	for (int i = 1; i <= n; ++i)
	{
		string str;
		cin >> str;
		map[i] = str;
		map2[str] = i;
	}

	for (int i = 0; i < m; ++i)
	{
		string str;
		cin >> str;
		if (map2[str] != 0)
			cout << map2[str] << "\n";
		else
			cout << map[atoi(str.c_str())] << "\n";
	}
}