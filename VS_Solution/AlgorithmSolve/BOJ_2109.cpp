#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct cmp
{
	bool operator()(pair<int, int>& a, pair<int, int>& b)
	{
		// ��¥(second)�� ��������, ����(first)�� �������� ����
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

	bool day[10001] = { false, };	// �ִ� 100000��

	while (!pq.empty())
	{
		auto p = pq.top(); pq.pop();

		// ���� Ž���� ����Ʈ����.
		for (int i = p.second; i >= 1; --i)
		{
			if (!day[i])	// �湮�� �� ������
			{
				day[i] = true;
				money += p.first;
				break;
			}
		}
	}

	cout << money << endl;
}