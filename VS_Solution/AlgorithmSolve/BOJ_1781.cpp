#include <iostream>
#include <queue>
#include <set>

using namespace std;

// �켱���� ť + �׸���
// ������� ���� �ִ��� �� �� �ִ� �� ���ϱ�

// ���� �ð��� 1�̶� �ܼ� �ϳ��� false�ε�
// �ð��� �ٸ� ����� �յ� ���ӱ��� ���ذ��鼭?
// ���ذ�


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
			// �޶��� �ʱⰪ�� �־��ش�
			dead = p.first;
			sum += p.second;
		}
	}
	*/


	cout << sum << endl;
}