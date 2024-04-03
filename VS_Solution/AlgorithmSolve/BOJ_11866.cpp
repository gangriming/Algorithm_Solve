#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
		q.push(i);

	queue<int> answer;

	while (!q.empty())
	{
		for (int i = 0; i < k-1; ++i)
		{
			auto temp = q.front();
			q.pop();
			q.push(temp);
		}

		answer.push(q.front());
		q.pop();
	}

	string str = "<";
	while (!answer.empty())
	{
		auto temp = answer.front();
		auto num = to_string(temp);
		if (answer.size() == 1)	// 마지막이면 안붙임.
			str += num;
		else
		{
			str += num + ", ";
		}
		answer.pop();
	}
	str += ">";

	cout << str << endl;
}