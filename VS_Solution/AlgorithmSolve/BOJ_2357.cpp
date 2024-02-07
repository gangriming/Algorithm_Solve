#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	// max_element?

	vector<long> v;
	for (int i = 0; i < n; ++i)
	{
		long temp;
		cin >> temp;
		v.push_back(temp);
	}

	// https://devhycho1107.tistory.com/61 새롭게 알게됨..
	// advance, next 둘다 이터레이터 이동.
	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;

		auto startidx = start - 1;
		auto endidx = end;

		auto max = max_element(next(v.begin(), startidx), next(v.begin(), endidx));
		auto min = min_element(next(v.begin(), startidx), next(v.begin(), endidx));
		
		cout << *min  << " " << *max << "\n";
	}

	// 음.. 테스트 케이스에 대해서는 통과를 하는데 시간 초과가 뜬다.ㅜㅜ
	// 세그먼트 트리로 접근해야 하는 문제 인 듯 한데..
	//https://www.acmicpc.net/blog/view/9
}