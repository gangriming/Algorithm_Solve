//#include <iostream>
//#include <string>
//#include <algorithm>
//
//using namespace std;
//
//int main()
//{
//	std::ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	// <queue>안쓰고..
//
//	int tc;
//	cin >> tc;
//
//	int myqueue[10005];
//	fill(myqueue, myqueue + 10005, -1);
//	int idx = 1;	// 현 인덱스
//	int size = 0;	// 현 사이즈
//
//	while (tc--)
//	{
//		string str;
//		cin >> str;
//
//		if (str == "push")
//		{
//			int num;
//			cin >> num;
//
//			myqueue[idx + size] = num;
//			size++;
//		}
//		else if (str == "pop")
//		{
//			cout << myqueue[idx] << "\n";
//			if (myqueue[idx] != -1)
//			{
//				myqueue[idx] = -1;
//				size--;
//			}
//			idx++;
//		}
//		else if (str == "size")
//		{
//			cout << size << "\n";
//		}
//		else if (str == "empty")
//		{
//			if (size == 0)
//				cout << "1\n";
//			else
//				cout << "0\n";
//		}
//		else if (str == "front")
//		{
//			if (size > 0)
//				cout << myqueue[idx] << "\n";
//			else
//				cout << "-1\n";
//		}
//		else if (str == "back")
//		{
//			if (size > 0)
//				cout << myqueue[size] << "\n";
//			else
//				cout << "-1\n";
//		}
//	}
//}

// ? 위 반례 다 돌아가는데 뭐가 문제인지..
// ======================================

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	deque<int> q;

	while (tc--)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int num;
			cin >> num;
			q.push_back(num);
		}
		else if (str == "pop")
		{
			if (q.empty())
				cout << "-1\n";
			else
			{
				cout << q.front() << "\n";
				q.pop_front();
			}
		}
		else if (str == "size")
		{
			cout << q.size() << "\n";
		}
		else if (str == "empty")
		{
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else if (str == "back")
		{
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
		}
	}
}