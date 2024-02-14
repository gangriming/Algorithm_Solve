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
	// 마지막 폴에 디스크가 다 올라왔다면
	if (p[2].size() >= disk)
		return;
}


int main()
{
	// 무조건 3개의 장대.
	for (int i = 0; i < 3; ++i)
		poll.push_back(stack<int>());

	// 하노이 탑
	cin >> disk;
	
	// 첫 장대에 세팅
	for(int i = disk; i > 0; --i)
		poll[0].push(i);
	
	towermove(poll);
}