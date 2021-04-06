#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(int a, int b)
	{
		// ���밪�� ���� ���� �� ���.
		// ���밪�� ������, ���� ���� �������� ���.
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	priority_queue<int, vector<int>, cmp> q;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			if (q.empty())
				cout << 0 << "\n";
			else
			{
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
			q.push(temp);
	}
}