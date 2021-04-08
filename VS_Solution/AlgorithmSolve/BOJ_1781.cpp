#include <iostream>
#include <queue>
#include <set>

using namespace std;

// 우선순위 큐 + 그리드
// 데드라인 내에 최대한 할 수 있는 양 구하기

// 단위 시간이 1이라서 단순 하나만 false인데
// 시간이 다른 경우라면 앞뒤 연속까지 비교해가면서?
// 미해결


struct cmp
{
	bool operator()(pair<int, int>a, pair<int, int>b)
	{
	//	if (a.first == b.first)
			return a.second < b.second;
	//	else
	//		return a.first > b.first;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	while (n--)
	{
		int deadline, cup;
		cin >> deadline >> cup;
		pq.push(make_pair(deadline, cup));
	}

	bool dead[200001] = { false, };
	int sum = 0;

	/*
	auto init = pq.top(); pq.pop();
	int dead = init.first;
	sum += init.second;

	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();
		if (dead != p.first)
		{
			// 달라진 초기값만 넣어준다
			dead = p.first;
			sum += p.second;
		}
	}
	*/


	cout << sum << endl;
}