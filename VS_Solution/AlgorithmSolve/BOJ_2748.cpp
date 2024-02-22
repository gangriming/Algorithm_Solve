#include <iostream>
#include <math.h>
#include <map>

using namespace std;

//vector<long> save;
// 맵으로 할까
map<int, long> save;

// top-down이어서 목표 숫자부터 들어올테니까
long pibonachi(int n)
{
	// 0, 1은 패스
	if (n < 2)
		return save[n] = n;


	if (save[n] > 0)	// 미리 구해서 저장한 값이 있다면
		return save[n];	// 바로 반환한다.
	else
	{
		// 아니라면 재귀를 사용해서 값을 구한다.
		save[n] = pibonachi(n - 1) + pibonachi(n - 2);
	}
	return save[n];
}


int main()
{
	int n;
	cin >> n;

	// top-down
	pibonachi(n);

	cout << save[n] << endl;
}