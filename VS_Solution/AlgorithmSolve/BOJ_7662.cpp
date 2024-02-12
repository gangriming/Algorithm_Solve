#include <iostream>
#include <set>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i)
	{
		int count;
		cin >> count;

		//priority_queue<int, vector<int>, greater<>> minheap;
		//priority_queue<int, vector<int>, less<>> maxheap;
		//map<int, int> check;
		// ���� ť�� �Ƚᵵ �Ǵ°ſ��µ�, ���� �̸��� �켱���� ť�� ��� ������ ����� �� �� ����.
		multiset<int> set;

		for (int j = 0; j < count; ++j)
		{
			char calc;
			int num;
			cin >> calc >> num;

			if (calc == 'I')	// insert
			{
				set.emplace(num);
			}
			else if (calc == 'D')	// delete
			{
				if (num == 1) // D 1 �ִ� ����
				{
					if (!set.empty())
						set.erase(--set.end());
				}
				else if(num == -1) // D -1 �ּڰ� ����
				{
					if (!set.empty())
						set.erase(set.begin());
				}
			}
		}

		if (set.empty())
			cout << "EMPTY\n";
		else
			cout << *(--set.end()) << " " <<  *set.begin() << "\n";
	}
}