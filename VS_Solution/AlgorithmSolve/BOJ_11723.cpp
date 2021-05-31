#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <vector>

using namespace std;

// https://chbuljumeok1997.tistory.com/42
// �� ��ũ�� string�� �����ڷ� �ڸ��� �پ��� ���

int main()
{
	//std::ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int m;
	cin >> m;

	//cin.ignore();

	auto bit = bitset<20>();

	while (m)
	{

		/*
		string s;
		cin.ignore();		// ���۸� ��������.
		getline(cin, s);	// ������ �ֱ� ������ getline �̿�.
		//cout << s;

		istringstream ss(s);
		string buf;

		vector<string> v;
		while (getline(ss, buf, ' '))
			v.push_back(buf);
		*/


		// v[0] = ����
		// v[1] = ��

		string s;
		cin >> s;

		if (s == "add")
		{
			string n;
			cin >> n;

			int num = atoi(n.c_str()) - 1;
			bit[num] = 1;
		}
		else if (s == "remove")
		{
			string n;
			cin >> n;

			int num = atoi(n.c_str()) - 1;
			bit[num] = 0;
		}
		else if (s == "check")
		{
			string n;
			cin >> n;

			int num = atoi(n.c_str()) - 1;
			//if (bit.test(num))
			//	cout << "1\n";
			//else
			//	cout << "0\n";
			cout << bit[num] << "\n";
		}
		else if (s == "toggle")
		{
			string n;
			cin >> n;

			int num = atoi(n.c_str()) - 1;
			bit.flip(num);
		}
		else if (s == "all")
		{
			bit.set();
		}
		else if (s == "empty")
		{
			bit.reset();
		}

		m--;
	}

}