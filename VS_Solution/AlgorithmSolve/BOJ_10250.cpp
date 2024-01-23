#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc = 0;
	cin >> tc;

	while (tc--)
	{
		int h, w, n = 0;
		cin >> h >> w >> n;

		// 방 수
		// 1 1 1일때 101이 나와야하는데 말이죠
		// 8 9 32도 804가 나와야 함.

		int floor = (n % h);
		int door = (n / h + 1);
		if (floor == 0) // 마지막 손님이라 이상하게되면
		{
			// 층 보정해준다.
			floor = h;
			door -= 1;
		}

		cout << floor * 100 + door << endl;
	}
}