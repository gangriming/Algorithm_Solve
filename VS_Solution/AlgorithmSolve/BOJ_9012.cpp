#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;


	for (int i = 0; i < t; ++i)
	{
		string str;
		cin >> str;

		bool flag = true;
		stack<char> s;

		for (int j = 0; j < str.length(); ++j)
		{
			if (str[j] == ')' && s.empty())
			{
				flag = false;
				break;
			}
			else
			{
				if (str[j] == '(')
					s.push(str[j]);
				else
				{
					if (s.top() == '(')
						s.pop();
				}
			}
		}
		if (s.empty() && flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}