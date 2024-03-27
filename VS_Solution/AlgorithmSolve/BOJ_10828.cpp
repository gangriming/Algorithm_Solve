#include <iostream>
#include <stack>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	stack<int> s;

	while (n--)
	{
		string str;
		int num;
		cin >> str;

		if (str == "push")
		{
			cin >> num;
			s.push(num);
		}
		else if (str == "pop")
		{
			if (s.empty())
				cout << "-1\n";
			else
			{
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (str == "size")
			cout << s.size() << "\n";
		else if (str == "empty")
		{
			if (s.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "top")
		{
			if (s.empty())
				cout << "-1\n";
			else
				cout << s.top() << "\n";
		}
	}
}