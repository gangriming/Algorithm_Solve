#include <iostream>
#include <queue>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int> q;

	int n;
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