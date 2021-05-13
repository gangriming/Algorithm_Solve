#include <iostream>
#include <map>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 이진트리 문제.
	// 트리.. 그래프.. 그래프 형태의 컨테이너 map, set
	// set은 operator[]가 안되어서 map으로 바꿔봄.
	// 반씩 나눠서 검색해보는 느낌이었던거 같은데.

	int n;
	cin >> n;

	map<int, int> m;
	
	for(int i = 0 ; i < n ; ++i)
	{
		int temp;
		cin >> temp;
		m.insert(make_pair(n, temp));
	}
}