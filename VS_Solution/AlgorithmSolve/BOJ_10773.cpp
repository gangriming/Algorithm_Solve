#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> k;

	stack<string> s;

	for (int i = 0; i < k; ++i)
	{
		string temp;
		cin >> temp;
		if (atoi(temp.c_str()) == 0 && !s.empty())
			s.pop();
		else
			s.push(temp);
	}

	long long sum = 0;
	int size = s.size();
	for (int i = 0; i < size; ++i)
	{
		sum += atoi(s.top().c_str());
		s.pop();
	}

	cout << sum << endl;
}