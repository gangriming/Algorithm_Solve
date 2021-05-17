#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <sstream>

using namespace std;

// https://chbuljumeok1997.tistory.com/42
// �� ��ũ�� string�� �����ڷ� �ڸ��� �پ��� ���

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m;
	cin >> m;

	auto bit = bitset<20>();

	while (m)
	{
		string s;
		getline(cin, s);	// ������ �ֱ� ������ getline �̿�.

		istringstream ss(s);
		string buf;
		vector<string> v;
		while (getline(ss, buf, ' '))
		{
			v.push_back(buf);
			cout << buf << endl;
		}

		m--;
	}

}