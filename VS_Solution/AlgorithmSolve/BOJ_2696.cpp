#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int size = 0;
		cin >> size;

		priority_queue<int, vector<int>> maxH;
		priority_queue<int, vector<int>, greater<int>> minH;
		vector<int> v;

		for (int j = 1; j <= size; ++j)
		{
			int temp;
			cin >> temp;
			if (maxH.empty())
				maxH.push(temp);			// 1. 초기엔 maxH에 삽입
			else
			{
				if (maxH.size() > minH.size())	// 2. maxH의 size는 
					minH.push(temp);			// minH과 같거나 하나가 더 크다
				else
					maxH.push(temp);
			}

			if (!maxH.empty() && !minH.empty() && maxH.top() > minH.top())	// 3. maxH의 top이 minH의 top보다 크면
			{
				int maxT = maxH.top();
				int minT = minH.top();

				maxH.pop(); minH.pop();

				maxH.push(minT);
				minH.push(maxT);
			}

			if (j % 2 == 1) // 홀수일때, 중앙값 출력
			{
				v.push_back(maxH.top());
			}
		}

		// 출력
		cout << v.size() << "\n";
		int count = 0;
		for (const auto value : v)
		{
			cout << value << " ";
			if (++count >= 10)
			{
				cout << "\n";
				count = 0;
			}
		}

	}
}
