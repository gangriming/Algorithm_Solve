#include <iostream>
#include <stack>

using namespace std;

int main()
{
	// 하노이 탑
	int disk = 0;
	cin >> disk;

	stack<int> a, b, c;
	
	for(int i = disk; i > 0; --i)
		a.push(i);
	
}