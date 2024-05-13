#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(const pair<string, int>& left, const  pair<string, int>& right) 
{
	if (left.second == right.second)
	{
		if (left.first.length() == right.first.length())
		{
			return left.first < right.first;
		}
		return left.first.length() > right.first.length();
	}
	else
		return left.second > right.second;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, int> mm;

	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;

		if (str.length() >= m)
			mm[str]++;
	}

	vector<pair<string, int>> data2(mm.begin(), mm.end());
	//sort(data2.begin(), data2.end(), cmp);	-
	sort(data2.begin(), data2.end(), cmp);

	for(const auto& v : data2)
	{
		cout << v.first << "\n";
	}
}