#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//map<long, long> save;
vector<long> save;


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long n;
	cin >> n;

	/*
		2 -> 1
		3 -> 1
		4 -> 2 -> 1
		5 -> 4 -> 2 -> 1
		....
		9 -> 3 -> 1
		여기서, 10이 2개의 분기가 생기는데
		10 -> 5 -> 4 -> 2 -> 1
		10 -> 9 -> 3 -> 1
		보면 2로 나눠진다고 나눠 들어가는거보다, 1을 빼는게 더 좋음.
		이런류 dp 문제는 안보이면 쭉 써보고 확인해보는게 빠를수 있을 것 같다.
	*/
	save.push_back(0);
	save.push_back(0);
	save.push_back(1);
	save.push_back(1);

	for (int i = 4; i <= n; ++i)
	{
		save.push_back(save[i - 1] + 1);	// 일단 1로 뺀 걸로 초기화해주고

		if (i % 6 == 0)			// 2, 3둘다 나누어지면, 2,3중에 더 적은게 -1보다 큰지
		{
			save[i] = min(min(save[i / 2] + 1, save[i / 3] + 1), save[i]);
		}
		else if (i % 3 == 0)	// 3으로 나누어지면, 1로 뺀거의 연산수와 비교해본다.
		{
			save[i] = min(save[i], save[i / 3] + 1);
		}
		else if (i % 2 == 0)	// 2로 나누어지면, 마찬가지로 비교해봄
		{
			save[i] = min(save[i], save[i / 2] + 1);
		}
		// 아니라면 2, 3둘다 안떨어지는거라서 -1빼는게 맞다.
	}

	cout << save[n] << endl;
}