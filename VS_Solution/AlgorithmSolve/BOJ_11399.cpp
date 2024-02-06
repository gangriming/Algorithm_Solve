#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		int minute;
		cin >> minute;
		v.push_back(minute);
	}
	
	sort(v.begin(), v.end(), less<>());

	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp = i;
		do
		{
			answer += v[temp];
		} while (--temp >= 0);
	}

	cout << answer << endl;
}