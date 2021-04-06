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

	priority_queue<int, vector<int>> maxH;
	priority_queue<int, vector<int>, greater<int>> minH;

	for (int i = 1; i <= n; ++i)
	{
		int num;
		cin >> num;

		if (maxH.empty())
		{
			maxH.push(num);
		}
		else
		{
			if (maxH.size() > minH.size())
				minH.push(num);
			else
				maxH.push(num);
		}

		if (!maxH.empty() && !minH.empty()
			&& maxH.top() > minH.top())
		{
			// max와 min의 top을 스왑한다.
			int maxT = maxH.top();
			int minT = minH.top();
			maxH.pop(); minH.pop();
			maxH.push(minT);
			minH.push(maxT);
		}


		if (i % 2 == 1)	// 홀수이면
		{
			cout << maxH.top() << "\n";
		}
		else
		{
			cout << ((maxH.top() > minH.top()) ? minH.top() : maxH.top()) << "\n";
		}

	}
}