#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<int, int, greater<>> m;

	int n;
	cin >> n;

	int size = n;

	while (n--)
	{
		int temp;
		cin >> temp;
		m[temp]++;
	}

	// »ê¼ú Æò±Õ
	long sum = 0;
	for (const auto& pair : m) 
	{
		sum += pair.first * pair.second;
	}
	double avg = (double)sum / size;
	cout << lround(avg) << "\n";

	// Áß¾Ó°ª
	if (m.size() == 1)
		cout << m.begin()->first << "\n";
	else
	{
		auto acccnt = 0;
		for (const auto& pair : m) {
			acccnt += pair.second;
			if (acccnt >= (size + 1) / 2) {
				cout << pair.first << "\n";
				break;
			}
		}
	}

	// ÃÖºó°ª
	set<int, greater<>> s;
	auto highest_value = *std::max_element(m.begin(), m.end(),
		[](const auto& pair1, const auto& pair2) {
			return pair1.second < pair2.second;
		});

	for (auto& value : m)
	{
		if (value.second == highest_value.second)
			s.insert(value.first);
	}

	if (s.size() == 1)
		cout << *s.begin() << "\n";
	else
		cout << *(--(--s.end())) << "\n";

	// ¹üÀ§
	if (m.size() == 1)
		cout << "0\n";
	else
	{
		auto maxnum = *m.begin();
		auto minnum = *(--m.end());
		cout << abs(maxnum.first - minnum.first) << "\n";
	}


}