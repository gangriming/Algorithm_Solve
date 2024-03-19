#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	// f = �� �ǹ��� �� ��
	// s = ���� �ִ� ��
	// g = ���� �ϴ� ��
	// u = ���� u�� ���� ��ư
	// d = �Ʒ��� d�� ���� ��ư

	vector<int> move(f+1, -1);
	vector<bool> visit(f+1, false);
	queue<int> q;

	if (s == g)
	{
		cout << "0\n";
		return 0;
	}

	q.push(s);
	move[s] = 0;
	visit[s] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		if (cur == g)
			break;

		auto upstair = cur + u;
		auto downstair = cur - d;

		if (f >= upstair && !visit[upstair])
		{
			q.push(upstair);
			visit[upstair] = true;
			move[upstair] = move[cur] + 1;
		}
		if (downstair >= 1 && !visit[downstair])
		{
			q.push(downstair);
			visit[downstair] = true;
			move[downstair] = move[cur] + 1;
		}
	}

	string str = move[g] == -1 ? "use the stairs" : to_string(move[g]);
	cout << str << endl;
}