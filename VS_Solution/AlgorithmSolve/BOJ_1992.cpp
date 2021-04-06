#include <iostream>
#include <cstdio> 
#pragma warning(disable:4996)

using namespace std;

int movie[65][65] = { 0, };

void quadtree(int x, int y, int edge)
{
	//cout << "(";

	int op[2] = { 0,0 };
	for (int i = x; i < x + edge; ++i)
	{
		for (int j = y; j < y + edge; ++j)
		{
			if (movie[i][j] == 0)
				op[0]++;
			else
				op[1]++;
		}
	}

	if (op[0] == edge * edge)
		cout << "0";
	else if (op[1] == edge * edge)
		cout << "1";
	else
	{
		if (edge >= 2)
		{
			cout << "(";
			quadtree(x, y, edge / 2);	//  왼쪽 위
			quadtree(x, y + edge / 2, edge / 2);
			quadtree(x + edge / 2, y, edge / 2);
			quadtree(x + edge / 2, y + edge / 2, edge / 2);
			cout << ")";
		}
	}
	//cout << ")";
}

int main()
{
	int n = 0;
	scanf("%d", &n);

	// n은 1에서 64까지만 들어온다.
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%1d", &movie[i][j]);
	

	quadtree(0, 0, n);

}