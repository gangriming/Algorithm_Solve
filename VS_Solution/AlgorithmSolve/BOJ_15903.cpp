#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int card, mix;
	cin >> card >> mix;

	priority_queue<long long, vector<long long>, greater<>> min_heap;

	for (int i = 0; i < card; ++i)
	{
		int num; 
		cin >> num;
		min_heap.push(num);
	}
	while (mix--)
	{
		auto a = min_heap.top(); min_heap.pop();
		auto b = min_heap.top(); min_heap.pop();

		min_heap.push(a + b);
		min_heap.push(a + b);
	}

	long long score = 0;
	while(!min_heap.empty())
	{
		score += min_heap.top();
		min_heap.pop();
	}
	cout << score << endl;

}