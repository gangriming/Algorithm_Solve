#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int>b)
	{
		if (a.second < b.second)
			return a > b;
		else
			return a < b;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

	int n = 0;
	cin >> n;
	while (n--)
	{
		int s, t;
		cin >> s >> t;
		pq.push(pair<int, int>(s, t));
	}
	int count = 0;
	
	cout << count << endl;
}