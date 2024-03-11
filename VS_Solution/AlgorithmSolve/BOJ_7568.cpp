#include <iostream>
#include <vector>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> people(n, make_pair(0, 0));
	vector<int> rank(n, 1);

	for (int i = 0; i < n; ++i)
		cin >> people[i].first >> people[i].second;

	for (int i = 0; i < n; ++i)
	{
		auto compare = people[i];

		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;

			if (compare.first < people[j].first && compare.second < people[j].second)
				rank[i]++;
		}
	}

	for (auto i : rank)
		cout << i << " ";
}