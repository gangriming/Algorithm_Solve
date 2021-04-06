#include <iostream>

using namespace std;

void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void func(int* arr, int n, int now, int m)
{
	if (now == m)
	{
		for (int i = 0; i <= m; ++i)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = now; i <= m; i++)
		{
			swap((arr + now), (arr + i));
			func(arr, n, now + 1, m);
			swap((arr + now), (arr + i)); //백트래킹
		}
	}
}

// Back-Tracking
int main()
{
	int n, m;
	cin >> n >> m;

	int arr[9] = { 1,2,3,4,5,6,7,8,9 };

	// n은 1에서 n까지의 수
	// m은 순열 조합의 개수?

	func(arr, n, 0, m - 1);

}

//#include <stdio.h>
//#include <string.h>
//void swap(char* x, char* y)
//{
//	char temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//}
//void permute(char* str, int l, int r)
//{
//	if (l == r)
//		printf("%s\n", str);
//	else
//	{
//		for (int i = l; i <= r; i++)
//		{
//			swap((str + l), (str + i));
//			permute(str, l + 1, r);
//			swap((str + l), (str + i)); //백트래킹
//		}
//	}
//}
//int main()
//{
//	char str[] = "ABC";
//	int n = strlen(str);
//	permute(str, 0, n - 1);
//	return 0;
//}
