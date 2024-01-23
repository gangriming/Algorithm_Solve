#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	for (int i = 0; i < tc; ++i)
	{
		string str;
		cin >> str;

		// 무조건 하나 이상이고 공백이 없으니까
		cout << str[0] << str.back() << endl;
	}

	return 0;
}