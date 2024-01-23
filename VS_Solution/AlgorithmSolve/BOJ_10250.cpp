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

		// �� ��
		// 1 1 1�϶� 101�� ���;��ϴµ� ������
		// 8 9 32�� 804�� ���;� ��.

		int floor = (n % h);
		int door = (n / h + 1);
		if (floor == 0) // ������ �մ��̶� �̻��ϰԵǸ�
		{
			// �� �������ش�.
			floor = h;
			door -= 1;
		}

		cout << floor * 100 + door << endl;
	}
}