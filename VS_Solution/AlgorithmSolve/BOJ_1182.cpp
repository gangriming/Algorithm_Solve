#include <iostream>

using namespace std;

int answer = 0;

void func_sum(int* arr, bool* visit, int count, int goal, int nowSum, int now)
{
	if (nowSum == goal)	// 목표치를 도착했으면
		answer++;	// 하나의 부분수열이 된다.
	else
	{
		for (int i = now; i < count; ++i)
		{
			if (!visit[i])
			{
				visit[i] = true;
				nowSum += arr[i];
				func_sum(arr, visit, count, goal, nowSum, now + 1);
				nowSum -= arr[i];
				visit[i] = false;
			}
		}
	}
}

int main()
{
	int count, sum = 0;
	cin >> count >> sum;

	int arr[20];
	bool visit[20] = { false, };
	for (int i = 0; i < count; ++i)
	{
		cin >> arr[i];
	}

	func_sum(arr, visit, count, sum, 0, 0);

	cout << answer << endl;
}