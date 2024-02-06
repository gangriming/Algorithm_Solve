#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v;

	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	// 큰 돈부터 탐색.
	int answer = 0;
	for (int i = v.size() - 1; i >= 0; --i)
	{
		// 0. 목표치를 이룬 상태라면 바로 중단.
		if (k <= 0)
			break;

		// 1. 동전이 목표값보다 크면 넘김.
		if (v[i] > k)
			continue;

		// 3. 현 동전에서 만들 수 있는만큼 만든다.
		answer += k / v[i];
		// 4. 남은 돈은 다음으로 넘긴다.
		k = k % v[i];
	}

	cout << answer << endl;
}