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

		// ������ �ϳ� �̻��̰� ������ �����ϱ�
		cout << str[0] << str.back() << endl;
	}

	return 0;
}