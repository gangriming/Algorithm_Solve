#include <iostream>
#pragma warning(disable:4996)

using namespace std;

int main()
{
	int n, m = 0;
	cin >> n >> m;

	char board[51][51] = { ' ' , };
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}


	int changeCount = 0;

	// 시작이 W면 다음줄은 B.
	// 시작이 B면 다음줄은 W.

	char firstCh = board[0][0];
	char changeCh;
	if (firstCh == 'W')
		changeCh = 'B';
	else
		changeCh = 'W';


	for (int i = 0; i < n - 8; ++i)
	{
		if (i > 0)
		{
			if (firstCh == 'W')
			{
				firstCh = 'B';
				changeCh = 'W';
			}
			else
			{
				firstCh = 'W';
				changeCh = 'B';
			}
		}

		for (int j = 0; j < m - 8; ++j)
		{
			if (board[i][j] != changeCh)
				changeCount++;

			if (changeCh == 'W')
				changeCh = 'B';
			else
				changeCh = 'W';
		
		}
	}

	cout << changeCount;

}