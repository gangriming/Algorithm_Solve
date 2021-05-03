#include <iostream>
#include <deque>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase = 0;
	cin >> testCase;

	while (testCase)
	{
		int count, curious;
		cin >> count >> curious;

		deque<pair<int, int>> dq;

		for (int i = 1; i <= count; ++i)
		{
			int imp;
			cin >> imp;
			dq.push_back(make_pair(i, imp));
		}

		int rank = 1;
		while (true)
		{
			if (!dq.empty())
			{
				int firstImp = dq[0].second;

				bool flag = true;

				for (int i = 1; i < dq.size(); ++i)
				{
					if (firstImp < dq[i].second)		// 중요도가 더 높다면
					{
						dq.push_back(dq[0]);
						dq.pop_front();
						flag = false;
						break;
					}
				}
				if (flag)	// 제일 중요도가 높다면
				{
					if (dq[0].first == curious + 1)
					{
						cout << rank << endl;
						dq.pop_front();
						break;
					}
					else
					{
						rank++;
						dq.pop_front();
					}
				}
			}
		}

		testCase--;
	}
}