#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	while (true)
	{
		string str;
		getline(cin, str);
		//getline(cin, str, '.');
		//cin >> str;

		if (str[0] == '.'/*str.empty()*/)
			break;

		stack<char> s;

		bool flag = true;
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == '(' || str[i] == ')')
			{
				if (s.empty() && str[i] == ')')
				{
					flag = false;
					break;
				}
				else
				{
					if (str[i] == '(')
						s.push(str[i]);
					else
						if (s.top() == '(' && str[i] == ')')
							s.pop();
						else
						{
							flag = false;
							break;
						}
				}
			}
			else if (str[i] == '[' || str[i] == ']')	// big
			{
				if (s.empty() && str[i] == ']')
				{
					flag = false;
					break;
				}
				else
				{
					if (str[i] == '[')
						s.push(str[i]);
					else
						if (s.top() == '[' && str[i] == ']')
							s.pop();
						else
						{
							flag = false;
							break;
						}
				}
			}
		}

		if (flag && s.empty())
		{
			cout << "yes" << endl;
		}
		else
			cout << "no" << endl;
	}
}