#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
	// R = ������
	// D = ������
	// ����ִµ� D ����ϸ� ���� (error)���.

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;
	cin >> t;


	for (int i = 0; i < t; ++i)
	{
		string str;		// ���
		cin >> str;	

		int count = 0;	// �迭�� ���� ��
		cin >> count;

		string arr;
		cin >> arr;

		deque<int> d;
		string num;

		bool isReverse = false;

		for (int i = 0; arr[i] != '\0'; ++i)
		{
			if (arr[i] >= 48 && arr[i] <= 57)	// ���ڸ� ����
			{
				num += arr[i];
			}
			else if (arr[i] == ',')
			{
				d.push_back(atoi(num.c_str()));
				num.clear();
			}
		}
		if(!num.empty())
			d.push_back(atoi(num.c_str()));
		
		bool flag = true;
		while (!str.empty())
		{
			//�տ������� ����� �����Ѵ�.
			if (str[0] == 'R')	// ������
			{
				//reverse(d.begin(), d.end());
				isReverse = !isReverse;	// ������ �������� �ð��� �����ɸ���.
			}
			else if (str[0] == 'D')	// �����
			{
				if (d.empty())
				{
					cout << "error" << endl;
					flag = false;
					break;
				}
				else
				{
					if (!isReverse)
						d.pop_front();
					else
						d.pop_back();
				}
			}
			str.erase(str.begin());
		}

		if (flag)
		{
			cout << "[";
			if (!isReverse)
			{
				for (int i = 0; i < d.size(); ++i)
				{
					cout << d[i];
					if (i != d.size() - 1)
						cout << ",";
				}
			}
			else
			{
				for (int i = d.size()-1 ; i >= 0; --i)
				{
					cout << d[i];
					if (i != 0)
						cout << ",";
				}

			}
			cout << "]" << endl;
		}

	}

}