#include <iostream>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
//
//struct info
//{
//	info(int e, int c) : edge(e), count(c) {};
//	int edge = 0;
//	int count = 0;
//};

int main()
{
	// 큐브는 정육면체. 한 변의 길이는 2의 제곱꼴.
	// 너무 잘못된 접근을 했다
	// 아예 재귀로 바꿔야됨 (분할정복으로)
	int length, width, height = 0;
	cin >> length >> width >> height;

	int kind = 0;
	cin >> kind;

	map<int, int, greater<int>> m;		// edge, count

	for (int i = 0; i < kind; ++i)
	{
		int a, b;
		cin >> a >> b;
		m.emplace(pow(2, a), b);
	}

	// 그리드니까
	// 제일 크고 적재할 수 있는 큐브를 넣고
	// 다음에 넣을 수 있는것을 넣고 이런 식으로.

	int maxVolume = length * width * height;
	
	int count = 0;
	for (auto& a : m)
		count += a.second;
	int answer = 0;

	while (maxVolume > 0 && count > 0)
	{
		if ((*m.begin()).second <= 0)
		{
			m.erase(m.begin());

			//for (auto& const a : m)
			//	count += a.second;
			continue;
		}
		int cube = pow((*m.begin()).first, 3);
		maxVolume -= cube;
		(*m.begin()).second -= 1;
		count -= 1;

		answer++;
	}


	cout << answer << endl;

}