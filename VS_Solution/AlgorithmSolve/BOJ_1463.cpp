#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//map<long, long> save;
vector<long> save;


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n;
	cin >> n;

	/*
		2 -> 1
		3 -> 1
		4 -> 2 -> 1
		5 -> 4 -> 2 -> 1
		....
		9 -> 3 -> 1
		���⼭, 10�� 2���� �бⰡ ����µ�
		10 -> 5 -> 4 -> 2 -> 1
		10 -> 9 -> 3 -> 1
		���� 2�� �������ٰ� ���� ���°ź���, 1�� ���°� �� ����.
		�̷��� dp ������ �Ⱥ��̸� �� �Ẹ�� Ȯ���غ��°� ������ ���� �� ����.
	*/
	save.push_back(0);
	save.push_back(0);
	save.push_back(1);
	save.push_back(1);

	for (int i = 4; i <= n; ++i)
	{
		save.push_back(save[i - 1] + 1);	// �ϴ� 1�� �� �ɷ� �ʱ�ȭ���ְ�

		if (i % 6 == 0)			// 2, 3�Ѵ� ����������, 2,3�߿� �� ������ -1���� ū��
		{
			save[i] = min(min(save[i / 2] + 1, save[i / 3] + 1), save[i]);
		}
		else if (i % 3 == 0)	// 3���� ����������, 1�� ������ ������� ���غ���.
		{
			save[i] = min(save[i], save[i / 3] + 1);
		}
		else if (i % 2 == 0)	// 2�� ����������, ���������� ���غ�
		{
			save[i] = min(save[i], save[i / 2] + 1);
		}
		// �ƴ϶�� 2, 3�Ѵ� �ȶ������°Ŷ� -1���°� �´�.
	}

	cout << save[n] << endl;
}