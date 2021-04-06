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
	// ť��� ������ü. �� ���� ���̴� 2�� ������.
	// �ʹ� �߸��� ������ �ߴ�
	// �ƿ� ��ͷ� �ٲ�ߵ� (������������)
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

	// �׸���ϱ�
	// ���� ũ�� ������ �� �ִ� ť�긦 �ְ�
	// ������ ���� �� �ִ°��� �ְ� �̷� ������.

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