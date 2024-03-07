#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool compare(pair<int, int>a, pair<int, int> b)
{
	// 종료가 같다면, 시작 시간이 빠른것으로.
	if (a.second == b.second)
		return a.first < b.first;

	// 아니라면 종료시간 순으로
	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), compare);

	int answer = 0;
	int endtime = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (endtime <= v[i].first)
		{
			answer++;
			//if(v[i].first != v[i].second) // 이 경우는 무한으로 시작-종료를 하기에
			endtime = v[i].second;
		}
	}

	cout << answer << endl;
} 