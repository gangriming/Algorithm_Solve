#include <iostream>
#include <queue>
#include <unordered_map>
#include <set>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	unordered_map<int, int> m;

	while (n--)
	{
		int deadline, cup;
		cin >> deadline >> cup;

		if (m[deadline] < cup)
			m[deadline] = cup;
	}

	long long sum = 0;
	for (auto& value : m)
		sum += value.second;

	cout << sum << endl;
}