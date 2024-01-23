#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//cin >> temp;	// cin은 공백을 짤라버림.
	// 공백까지 입력받으려면 getline을 사용해야함.
	//while (getline(cin, temp))	// getline자체가 eof가 오면 false라서, 안에서 처리할필요가 없다.
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