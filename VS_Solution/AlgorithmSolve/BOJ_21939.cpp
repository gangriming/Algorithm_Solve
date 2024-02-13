#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// set으로 풀려고 했었음..
struct functor
{
	bool operator() (const pair<int, int>& left, const pair<int, int>& right) const
	{
		if (left.second != right.second) {
			return left.second > right.second;  // second값이 큰 순으로
		}
		else {
			return left.first > right.first;    // second값이 같다면, first값이 큰 순으로
		}
	}
};


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a;
	cin >> a;
	
	// 이렇게 중간에 삭제해야 하는 경우는, 우선순위 큐가 의미 없지 않나.
	// set이 낫지 않을까?
	multiset<pair<int, int>, functor> set;
	// 이런 문제들은 map을 두고, 마킹용으로 사용하는 것 같다.
	// 감 익혀보자
	map<int, int> difficulty_mark;

	while (a--)
	{
		int num, difficulty;
		cin >> num >> difficulty;
		set.emplace(make_pair(num, difficulty));
		difficulty_mark[num] = difficulty;
	}

	int b;
	cin >> b;

	while (b--)
	{
		string str;
		cin >> str;

		if (str == "add")
		{
			int a, b;
			cin >> a >> b;
			set.emplace(make_pair(a, b));
			difficulty_mark[a] = b;
		}
		else if (str == "solved")
		{
			int a;
			cin >> a;

			// 마크만 하고, 실제로는 지우지 않기 때문에 같은 번호가 다른 난이도로 갱신될때 문제가 됨
			// 차라리 erase말고, -1이나 이런걸로 하는게...
			//mark.erase(mark.find(a));
			auto difficult = difficulty_mark[a];
			set.erase(set.find(make_pair(a, difficult)));

			difficulty_mark[a] = 0;
		}
		else if (str == "recommend")
		{
			int a;
			cin >> a;
			if (a > 0) // 가장 어려운
			{

				cout << set.begin()->first << "\n";
				//while (true)
				//{
				//	// 만약에 정렬된걸 꺼냈는데
				//	if (difficulty_mark.find(set.begin()->first) == difficulty_mark.end())
				//	{
				//		// 내가 푼거였으면, 다시 꺼낸다.
				//		set.erase(set.begin());
				//	}
				//	else
				//	{
				//		// 아니면 출력
				//		cout << set.begin()->first << "\n";
				//		break;
				//	}
				//}
			}
			else // 가장 쉬운 
			{
				cout << (--set.end())->first << "\n";
			//	while (true)
			//	{
			//		// 만약에 정렬된걸 꺼냈는데
			//		if (difficulty_mark.find((--set.end())->first) == difficulty_mark.end())
			//		{
			//			// 내가 푼거였으면, 다시 꺼낸다.
			//			set.erase(--set.end());
			//		}
			//		else
			//		{
			//			// 아니면 출력
			//			cout << (--set.end())->first << "\n";
			//			break;
			//		}
			//	}
			}
		}
	}
}