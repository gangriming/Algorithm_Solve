#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>	// Ʃ�þ��� ����ü����?

using namespace std;

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b)
{
	/*
	���� ������ �����ϴ� ������
	���� ������ ������ ���� ������ �����ϴ� ������
	���� ������ ���� ������ ������ ���� ������ �����ϴ� ������
	��� ������ ������ �̸��� ���� ������ �����ϴ� ������ (��, �ƽ�Ű �ڵ忡�� �빮�ڴ� �ҹ��ں��� �����Ƿ� ���������� �տ� �´�.)
	*/
	// < ��������, > ��������
	
	if (get<1>(a) != get<1>(b))
		return get<1>(a) > get<1>(b);
	else
	{
		if (get<2>(a) != get<2>(b))
			return get<2>(a) < get<2>(b);
		else
		{
			if (get<3>(a) != get<3>(b))
				return get<3>(a) > get<3>(b);
			else
			{
				// �ٰ�����
				return get<0>(a) < get<0>(b);
			}
		}
	}

}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<tuple<string, int, int, int>> v;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;

		v.push_back(make_tuple(name, a, b, c));
	}

	sort(v.begin(), v.end(), compare);

	for (auto& value : v)
		cout << get<0>(value) << "\n";
}