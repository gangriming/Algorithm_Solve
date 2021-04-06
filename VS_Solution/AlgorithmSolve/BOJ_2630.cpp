#include <iostream>
#include <vector>

//  21.02,10
using namespace std;

int blue = 0;
int white = 0;
int paper[129][129] = { 0, };

// 시작점, 끝점, 검사할 변의 수를 알아야 한다.
void DividePaper(/*vector<vector<int>> p,*/ int x, int y, int edge)
{
	// x = 시작 x좌표 // y = 시작 y좌표
	int op[2] = { 0,0 };	// op[0] = 하얀색, op[1] = 파란색의 개수

	for (int i = y; i < y + edge; ++i)		// y + edge가 포인트.
	{
		for (int j = x; j < x + edge; ++j)
		{
			if (paper[i][j] == 0)
				op[0]++;
			else
				op[1]++;
		}
	}

	if (op[0] == edge * edge)			// 모든 칸이 동일한 경우
		white++;
	else if (op[1] == edge * edge)		// 모든 칸이 동일한 경우
		blue++;
	else								// 분할이 필요한 경우 
	{
		if (edge >= 2)
		{
			//DividePaper(p, x, y, edge / 2);
			//DividePaper(p, x + edge / 2, y, edge / 2);
			//DividePaper(p, x, y + edge / 2, edge / 2);
			//DividePaper(p, x + edge / 2, y + edge / 2, edge / 2);
			DividePaper(x, y, edge / 2);
			DividePaper(x + edge / 2, y, edge / 2);
			DividePaper(x, y + edge / 2, edge / 2);
			DividePaper(x + edge / 2, y + edge / 2, edge / 2);
		
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	// n은 자를 수 있게 2의 제곱수로 들어온다.

	//vector<vector<int>> paper(n, vector<int>(n, 0));	// nxn 2차원배열

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> paper[i][j];
		}
	}

	// 전체 종이가 같은 색이 아니라면 -> 가로 반 세로 반
	// -> 자른것들이 같은 색이 아니라면 -> 또 가로 반 세로 반 반복.

	DividePaper(0, 0, n);

	cout << white << endl << blue << endl;

}
