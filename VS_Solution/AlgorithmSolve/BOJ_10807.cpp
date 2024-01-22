#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, v, cnt = 0;
	vector<int> vec;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		vec.push_back(temp);
	}

	cin >> v;


	for (int i = 0; i < vec.size(); ++i)
	{
		if (vec[i] == v)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}