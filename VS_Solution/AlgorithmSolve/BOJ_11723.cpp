#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <sstream>

using namespace std;

// https://chbuljumeok1997.tistory.com/42
// 위 링크는 string을 구분자로 자르는 다양한 방법

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
		getline(cin, s);	// 공백이 있기 떄문에 getline 이용.

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