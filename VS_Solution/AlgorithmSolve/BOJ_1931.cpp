#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool compare(pair<int, int>a, pair<int, int> b)
{
	// 회의 시간이 짧은것.
	auto atime = abs(a.first - a.second);
	auto btime = abs(b.first - b.second);

	if (atime < btime)
		return true;
	else if (atime > btime)
		return false;
	else  
	{
		// 같으면 시작 시간이 빠른것으로 첫 접근 했었는데,
		// https://velog.io/@junttang/BOJ-1931-%ED%9A%8C%EC%9D%98%EC%8B%A4-%EB%B0%B0%EC%A0%95-%ED%95%B4%EA%B2%B0-%EC%A0%84%EB%9E%B5-C
		// 종료시간이 빠른것 으로 정렬
		return a.first > b.first;
	}
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		if (b > max) max = b;
	}

	sort(v.begin(), v.end(), compare);

	vector<int> time(max+1, 0);
	int answer = 0;
	int pre_same = -1;
	for (int i = 0; i < v.size(); ++i)
	{
		// 흐음..
		auto start = v[i].first;
		auto end = v[i].second;
		
		// 접근방법이 틀렸는데, 지금 이해가 잘 안돼서 내일 보는게.. 

		if ((time[start] == 0 && time[end] == 0))	// 비어 있으면
		{
			answer++;
			for (int j = start; j <= end; ++j)
				time[j] = 1;
		}
	}

	cout << answer << endl;
} 