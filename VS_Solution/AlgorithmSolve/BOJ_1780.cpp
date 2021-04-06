#include <iostream>
#include <vector>
using namespace std;


int paper[3] = { 0, };	// -1, 0, 1�� ����

// �ʿ��� ��
// 1. �߶� �� ����
// 2. �� ���̴� �� ĭ����?

void MatrixSearch(vector<vector<int>>& mat
	, int paperCount, int startX, int startY)
{
	// paperCount = �� ���̴� �� ĭ?
	// start = �����ϴ� ĭ
	
	// ĭ�� �� �����鼭, �� ���� ������ üũ�Ѵ�.
	int init = mat[startY][startX];
	bool isCorrect = true;
	
	for (int i = startY; i < startY + paperCount; ++i)
	{
		for (int j = startX; j < startX + paperCount; ++j)
		{
			if (init != mat[i][j])
			{
				isCorrect = false;
				break;
			}
		}
	}

	// ���̰� �� ���� ���
	if (isCorrect)
	{
		switch (init)
		{
		case -1:
			paper[0]++;
			break;
		case 0:
			paper[1]++;
			break;
		case 1:
			paper[2]++;
			break;
		}
	}
	else
	{
		// ��͸� �¿��.
		// 9���� ������� ��.
		int divideCount = paperCount / 3;
		MatrixSearch(mat, divideCount, startX, startY);
		MatrixSearch(mat, divideCount, startX + divideCount, startY);
		MatrixSearch(mat, divideCount, startX + divideCount * 2, startY);

		MatrixSearch(mat, divideCount, startX, startY + divideCount);
		MatrixSearch(mat, divideCount, startX + divideCount, startY + divideCount);
		MatrixSearch(mat, divideCount, startX + divideCount * 2, startY + divideCount);

		MatrixSearch(mat, divideCount, startX, startY + divideCount * 2);
		MatrixSearch(mat, divideCount, startX + divideCount, startY + divideCount * 2);
		MatrixSearch(mat, divideCount, startX + divideCount * 2, startY + divideCount * 2);	
	}

}

int main()
{
	int count = 0;
	cin >> count;

	vector<vector<int>> matrix(count + 1, vector<int>(count + 1, 0));

	for (int i = 1; i <= count ; ++i)
	{
		for (int j = 1; j <= count ; ++j)
		{
			int temp = 0;
			cin >> temp;
			matrix[i][j] = temp;
		}
	}

	MatrixSearch(matrix, count, 1, 1);	// ������ ������ ���̿���.

	cout << paper[0] << endl << paper[1] << endl << paper[2] << endl;
}