#include <iostream>
#include <queue>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;

	while (n--)
	{
		int temp;
		cin >> temp;
		pq.push(temp);
	}

	int sum = 0;

	if (pq.size() != 1)
	{
		while (pq.size() != 1)
		{
			int first = pq.top(); pq.pop();
			int second = pq.top(); pq.pop();

			sum += first + second;
			pq.push(first + second);
		}
	}
	else
	{
		if(pq.top() > 1)
			sum = pq.top();
	}

	if (pq.size() == 1)
	{
		cout << sum << endl;
	}
}