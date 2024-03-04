#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int H, W;
	cin >> H >> W;
	vector<int> heights(W);
	for (int i = 0; i < W; ++i)
	{
		cin >> heights[i];
	}

	int total_water = 0;
	for (int i= 1; i < W - 1; ++i)   // ù ��°�� ������ ĭ�� ���� ������ �����Ƿ� ����
	{
		// 1. ��, ������ ������ ���� ���� Ȯ��
		int left_max = *max_element(heights.begin(), heights.begin() + i);
		int right_max = *max_element(heights.begin() + i + 1, heights.end());
		// 2. ���� ������ ���� ����.
		int water_level = min(left_max, right_max);
		// 3. ���� üũ�ϴ� ���� ���̰�, ���� ���̺��� ������ ���δ�.
		if (water_level > heights[i]) 
		{
			total_water += water_level - heights[i];
		}
	}
	cout << total_water << endl;
	return 0;
}