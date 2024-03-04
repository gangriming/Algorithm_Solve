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
	for (int i= 1; i < W - 1; ++i)   // 첫 번째와 마지막 칸은 물이 고이지 않으므로 제외
	{
		// 1. 왼, 오에서 감싸줄 벽의 높이 확인
		int left_max = *max_element(heights.begin(), heights.begin() + i);
		int right_max = *max_element(heights.begin() + i + 1, heights.end());
		// 2. 낮은 벽까지 물이 찬다.
		int water_level = min(left_max, right_max);
		// 3. 현재 체크하는 곳의 높이가, 물의 높이보다 낮으면 고인다.
		if (water_level > heights[i]) 
		{
			total_water += water_level - heights[i];
		}
	}
	cout << total_water << endl;
	return 0;
}