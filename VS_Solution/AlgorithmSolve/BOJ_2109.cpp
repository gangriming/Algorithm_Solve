#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct cmp
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		// 날짜(second)는 오름차순, 페이(first)는 내림차순 정렬
		//if (a.second == b.second)
		//	return a.first < b.first;
		//else
		//	return a.second > b.second;
		return a.first < b.first;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	int n;
	cin >> n;

	while (n--)
	{
		int p, d;
		cin >> p >> d;

		pq.push(make_pair(p, d));
	}

	int money = 0;

	bool day[10001] = { false, };	// 최대 100000일

	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();

		// 역순 탐색이 포인트였음.
		for (int i = p.second; i >= 1; --i)
		{
			if (!day[i])	// 방문할 수 있으면
			{
				day[i] = true;
				money += p.first;
				break;
			}
		}
	}

	cout << money << endl;
}