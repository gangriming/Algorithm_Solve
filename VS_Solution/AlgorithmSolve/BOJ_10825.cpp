#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>	// 튜플쓸까 구조체쓸까?

using namespace std;

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b)
{
	/*
	국어 점수가 감소하는 순서로
	국어 점수가 같으면 영어 점수가 증가하는 순서로
	국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
	모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
	*/
	// < 오름차순, > 내림차순
	
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
				// 다같으면
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