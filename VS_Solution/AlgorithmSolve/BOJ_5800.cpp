#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1 ; i <= n ; i++)
	{
		int k;
		cin >> k;

		vector<int> l(k);

		for (int i = 0; i < k; ++i)
			cin >> l[i];

		sort(l.begin(), l.end(), greater<>());

		int gap = -1;
		for (int i = 0; i < k - 1; ++i)
			gap = max(abs(l[i] - l[i + 1]), gap);

		cout << "Class " << i << endl;
		cout << "Max " << l[0] << ", Min " << l[l.size() - 1] << ", Largest gap " << gap << endl;
	}
}