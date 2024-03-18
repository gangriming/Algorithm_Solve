#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<bool> visit(100001, false);
	vector<int> move(100001, 0);

	// 1. 뒤로 걷 x-1
	// 2. 앞으로 걷 x+1
	// 3. 순간이동 x * 2

	if (n == k)	// 지금 있는곳이 동생이 있는곳이면, 끝.
	{
		cout << "0\n";
		return 0;
	}

	queue<int> q;
	q.push(n);

	while (!q.empty())
	{
		auto pos = q.front();
		q.pop();

		if (pos == k)
			break;

		// 1
		if (pos - 1 >= 0 && visit[pos - 1] == false)
		{
			visit[pos - 1] = true;
			move[pos - 1] = move[pos] + 1;
			q.push(pos - 1);
		}
		// 2
		if (pos + 1 <= visit.size() - 1 && visit[pos + 1] == false)
		{
			visit[pos + 1] = true;
			move[pos + 1] = move[pos] + 1;
			q.push(pos + 1);
		}
		if (pos * 2 <= visit.size() - 1 && visit[pos * 2] == false)
		{
			visit[pos * 2] = true;
			move[pos * 2] = move[pos] + 1;
			q.push(pos * 2);
		}

		if (pos - 1 == k || pos + 1 == k || pos * 2 == k)
			break;
	}

	cout << move[k] << endl;
}