#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	// 1번 해답
	// n이 30 이하라는 전제가 있기에, 1번도 O(n)이어서 좋은 알고리즘이다.
	//int answer = 0;
	//vector<int> uniform(n + 2, 1);	// 앞, 뒤로 허수를 넣어준다.

	//// 1. 더 가져온 애들 + 1
	//for (int i = 0; i < reserve.size(); ++i)
	//	uniform[reserve[i]]++;

	//// 2. 잃어버린 애들 뺌
	//for (int i = 0; i < lost.size(); ++i)
	//	uniform[lost[i]]--;

	//// 줄 수 있는 애들은 앞, 뒤로 찾아봄.
	//for (int i = 1; i < uniform.size(); ++i)
	//{
	//	// 내 유니폼이 두개면서 앞이 없다. 먼저 하는 행동을 먼저 ..
	//	if (uniform[i] == 2 && uniform[i - 1] == 0)
	//		uniform[i] = uniform[i - 1] = 1;
	//	else if (uniform[i] == 2 && uniform[i + 1] == 0)
	//		uniform[i] = uniform[i + 1] = 1;
	//}

	//for (int i = 1; i <= n; ++i)
	//{
	//	if (uniform[i] >= 1)
	//		answer++;
	//}
	//return answer;


	// 2번
	unordered_set<int> l(lost.begin(), lost.end());
	set<int> r;
	unordered_set<int> inter;	// l , r의 교집합

	for (auto& x : reserve) {
		// l에 들어있으면 가져오고 잃어버린것.
		if (l.find(x) == l.end())	// l에 없다면
			r.insert(x);
		else // l에 있다면 교집합에
			inter.insert(x);
	}

	// 이러면 r에 번호 순서에 맞게 들어있음. (set이어서)

	// 가져왔는데 잃어버린 애들은(자기것이 있는 애들은) lost명단에서 지워줌.
	for (auto& x : inter)
		l.erase(x);

	for (auto& x : r)
	{
		// 없는애들이 내 앞에있는애가 있는지?
		if (l.find(x - 1) != l.end())
			l.erase(x - 1);
		else if (l.find(x + 1) != l.end()) // 내 뒤에있는 애한테 빌려줄 수 있는지?
			l.erase(x + 1);
	}

	return n - l.size();

}

int main()
{

}