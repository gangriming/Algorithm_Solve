#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int tc;
	cin >> tc;

	while (tc--)
	{
		int yon, kor = 0;

		for (int i = 0; i < 9; ++i)
		{
			int a, b = 0;
			cin >> a >> b;
			yon += a;
			kor += b;
		}

		if (yon > kor)
			cout << "Yonsei\n";
		else if (yon < kor)
			cout << "Korea\n";
		else
			cout << "Draw\n";
	}

}