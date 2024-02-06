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

	// ū ������ Ž��.
	int answer = 0;
	for (int i = v.size() - 1; i >= 0; --i)
	{
		// 0. ��ǥġ�� �̷� ���¶�� �ٷ� �ߴ�.
		if (k <= 0)
			break;

		// 1. ������ ��ǥ������ ũ�� �ѱ�.
		if (v[i] > k)
			continue;

		// 3. �� �������� ���� �� �ִ¸�ŭ �����.
		answer += k / v[i];
		// 4. ���� ���� �������� �ѱ��.
		k = k % v[i];
	}

	cout << answer << endl;
}