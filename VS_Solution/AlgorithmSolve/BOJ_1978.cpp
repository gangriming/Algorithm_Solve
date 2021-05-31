#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int count = 0;
	while (n)
	{
		int temp;
		cin >> temp;

		bool flag = true;
		int debug = 0;

		for (int i = 2; i <= temp; ++i)
		{
			if (i % temp == 0)
			{
				debug++;
			}
			if (debug > 1)
			{
				flag = false;
				break;
			}
			
		}

		if (flag && temp != 1)		// 1은 소수가 아니다
			count++;

		n--;
	}
	cout << count << "\n";
}