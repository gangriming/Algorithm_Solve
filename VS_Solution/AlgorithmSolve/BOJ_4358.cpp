#include <iostream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> m;

	string str;
	int cnt = 0; 

	cout << fixed << setprecision(4);

	while (getline(cin, str))
	{
		m[str]++;
		cnt++;
	}

	for (const auto& v : m)
	{
		cout << v.first << " " << ((double)v.second / (double)cnt) * 100.0 << "\n";
	}


}