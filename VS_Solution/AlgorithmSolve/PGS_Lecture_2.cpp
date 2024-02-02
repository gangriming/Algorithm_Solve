#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	// 1�� �ش�
	// n�� 30 ���϶�� ������ �ֱ⿡, 1���� O(n)�̾ ���� �˰����̴�.
	//int answer = 0;
	//vector<int> uniform(n + 2, 1);	// ��, �ڷ� ����� �־��ش�.

	//// 1. �� ������ �ֵ� + 1
	//for (int i = 0; i < reserve.size(); ++i)
	//	uniform[reserve[i]]++;

	//// 2. �Ҿ���� �ֵ� ��
	//for (int i = 0; i < lost.size(); ++i)
	//	uniform[lost[i]]--;

	//// �� �� �ִ� �ֵ��� ��, �ڷ� ã�ƺ�.
	//for (int i = 1; i < uniform.size(); ++i)
	//{
	//	// �� �������� �ΰ��鼭 ���� ����. ���� �ϴ� �ൿ�� ���� ..
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


	// 2��
	unordered_set<int> l(lost.begin(), lost.end());
	set<int> r;
	unordered_set<int> inter;	// l , r�� ������

	for (auto& x : reserve) {
		// l�� ��������� �������� �Ҿ������.
		if (l.find(x) == l.end())	// l�� ���ٸ�
			r.insert(x);
		else // l�� �ִٸ� �����տ�
			inter.insert(x);
	}

	// �̷��� r�� ��ȣ ������ �°� �������. (set�̾)

	// �����Դµ� �Ҿ���� �ֵ���(�ڱ���� �ִ� �ֵ���) lost��ܿ��� ������.
	for (auto& x : inter)
		l.erase(x);

	for (auto& x : r)
	{
		// ���¾ֵ��� �� �տ��ִ¾ְ� �ִ���?
		if (l.find(x - 1) != l.end())
			l.erase(x - 1);
		else if (l.find(x + 1) != l.end()) // �� �ڿ��ִ� ������ ������ �� �ִ���?
			l.erase(x + 1);
	}

	return n - l.size();

}

int main()
{

}