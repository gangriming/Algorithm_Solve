#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//cin >> temp;	// cin�� ������ ©�����.
	// ������� �Է¹������� getline�� ����ؾ���.
	//while (getline(cin, temp))	// getline��ü�� eof�� ���� false��, �ȿ��� ó�����ʿ䰡 ����.
	//{
	//	cout << temp;
	//}
	while (true)
	{
		string temp;
		getline(cin, temp);

		if (cin.eof())
			return 0;
		cout << temp << endl;
	}
}