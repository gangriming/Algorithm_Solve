#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	vector<int> v;

	for (int i = 0; i < 10; ++i)
	{
		int temp;
		cin >> temp;

		v.push_back(temp);
	}

	int sum = 0;
	for (auto& value : v)
	{
		// 100에 가까운수가 두개라면 큰값.
		// 딱 100으로 떨어지면 제일 좋고..
		
		// 꺼낸걸 더해서 100이 넘는지?
		auto preview_sum = value + sum;
		if (preview_sum >= 100)
		{
			// 차를 구해서, 차가 같으면 높은걸로.
			int gab_a = abs(sum - 100);
			int gab_b = abs(preview_sum - 100);

			if (gab_a == gab_b || gab_a > gab_b)
			{
				sum = preview_sum;
				break;
			}
			else
			{
				break;
			}
		}
		else // 안넘으면 더하고 다음
			sum += value;
	}

	cout << sum << endl;
}