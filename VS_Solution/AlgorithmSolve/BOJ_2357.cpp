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

	// https://devhycho1107.tistory.com/61 ���Ӱ� �˰Ե�..
	// advance, next �Ѵ� ���ͷ����� �̵�.
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

	// ��.. �׽�Ʈ ���̽��� ���ؼ��� ����� �ϴµ� �ð� �ʰ��� ���.�̤�
	// ���׸�Ʈ Ʈ���� �����ؾ� �ϴ� ���� �� �� �ѵ�..
	//https://www.acmicpc.net/blog/view/9
}