#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << "0" << endl;
		return 0;
	}
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end(), greater<int>());

	// 몇명을 잘라야 하는지?
	int cut = round(n * 0.15);
	long average = 0;

	//if (cut > 0)
	//{
	//	for (int i = cut; i <= n - cut; ++i)
	//		average += v[i];
	//}
	//else
	//{
	//	for (int i = 0; i < n; ++i)
	//		average += v[i];
	//}
	for (int i = cut; i < n - cut; ++i)
		average += v[i];

	cout << round(static_cast<double>(average) / (n - cut * 2)) << endl;
}