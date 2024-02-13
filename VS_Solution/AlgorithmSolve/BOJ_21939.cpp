#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

// set���� Ǯ���� �߾���..
struct functor
{
	bool operator() (const pair<int, int>& left, const pair<int, int>& right) const
	{
		if (left.second != right.second) {
			return left.second > right.second;  // second���� ū ������
		}
		else {
			return left.first > right.first;    // second���� ���ٸ�, first���� ū ������
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
	
	// �̷��� �߰��� �����ؾ� �ϴ� ����, �켱���� ť�� �ǹ� ���� �ʳ�.
	// set�� ���� ������?
	multiset<pair<int, int>, functor> set;
	// �̷� �������� map�� �ΰ�, ��ŷ������ ����ϴ� �� ����.
	// �� ��������
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

			// ��ũ�� �ϰ�, �����δ� ������ �ʱ� ������ ���� ��ȣ�� �ٸ� ���̵��� ���ŵɶ� ������ ��
			// ���� erase����, -1�̳� �̷��ɷ� �ϴ°�...
			//mark.erase(mark.find(a));
			auto difficult = difficulty_mark[a];
			set.erase(set.find(make_pair(a, difficult)));

			difficulty_mark[a] = 0;
		}
		else if (str == "recommend")
		{
			int a;
			cin >> a;
			if (a > 0) // ���� �����
			{

				cout << set.begin()->first << "\n";
				//while (true)
				//{
				//	// ���࿡ ���ĵȰ� ���´µ�
				//	if (difficulty_mark.find(set.begin()->first) == difficulty_mark.end())
				//	{
				//		// ���� Ǭ�ſ�����, �ٽ� ������.
				//		set.erase(set.begin());
				//	}
				//	else
				//	{
				//		// �ƴϸ� ���
				//		cout << set.begin()->first << "\n";
				//		break;
				//	}
				//}
			}
			else // ���� ���� 
			{
				cout << (--set.end())->first << "\n";
			//	while (true)
			//	{
			//		// ���࿡ ���ĵȰ� ���´µ�
			//		if (difficulty_mark.find((--set.end())->first) == difficulty_mark.end())
			//		{
			//			// ���� Ǭ�ſ�����, �ٽ� ������.
			//			set.erase(--set.end());
			//		}
			//		else
			//		{
			//			// �ƴϸ� ���
			//			cout << (--set.end())->first << "\n";
			//			break;
			//		}
			//	}
			}
		}
	}
}