#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool compare(pair<int, int>a, pair<int, int> b)
{
	// ���ᰡ ���ٸ�, ���� �ð��� ����������.
	if (a.second == b.second)
		return a.first < b.first;

	// �ƴ϶�� ����ð� ������
	return a.second < b.second;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), compare);

	int answer = 0;
	int endtime = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (endtime <= v[i].first)
		{
			answer++;
			//if(v[i].first != v[i].second) // �� ���� �������� ����-���Ḧ �ϱ⿡
			endtime = v[i].second;
		}
	}

	cout << answer << endl;
} 