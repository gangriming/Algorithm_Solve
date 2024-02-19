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
		// 100�� �������� �ΰ���� ū��.
		// �� 100���� �������� ���� ����..
		
		// ������ ���ؼ� 100�� �Ѵ���?
		auto preview_sum = value + sum;
		if (preview_sum >= 100)
		{
			// ���� ���ؼ�, ���� ������ �����ɷ�.
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
		else // �ȳ����� ���ϰ� ����
			sum += value;
	}

	cout << sum << endl;
}