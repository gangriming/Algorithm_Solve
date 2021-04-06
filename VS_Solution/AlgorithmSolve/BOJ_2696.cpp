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
				maxH.push(temp);			// 1. �ʱ⿣ maxH�� ����
			else
			{
				if (maxH.size() > minH.size())	// 2. maxH�� size�� 
					minH.push(temp);			// minH�� ���ų� �ϳ��� �� ũ��
				else
					maxH.push(temp);
			}

			if (!maxH.empty() && !minH.empty() && maxH.top() > minH.top())	// 3. maxH�� top�� minH�� top���� ũ��
			{
				int maxT = maxH.top();
				int minT = minH.top();

				maxH.pop(); minH.pop();

				maxH.push(minT);
				minH.push(maxT);
			}

			if (j % 2 == 1) // Ȧ���϶�, �߾Ӱ� ���
			{
				v.push_back(maxH.top());
			}
		}

		// ���
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
