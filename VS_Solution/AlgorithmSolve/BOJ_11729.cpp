#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<stack<int>> poll;
int disk = 0;
int movecnt = 0;

// ^^:;
void towermove(vector<stack<int>>& p)
{
	// ������ ���� ��ũ�� �� �ö�Դٸ�
	if (p[2].size() >= disk)
		return;
}


int main()
{
	// ������ 3���� ���.
	for (int i = 0; i < 3; ++i)
		poll.push_back(stack<int>());

	// �ϳ��� ž
	cin >> disk;
	
	// ù ��뿡 ����
	for(int i = disk; i > 0; --i)
		poll[0].push(i);
	
	towermove(poll);
}