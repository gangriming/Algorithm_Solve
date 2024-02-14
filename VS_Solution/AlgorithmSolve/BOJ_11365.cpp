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

		if (str == "END")
			return 0;

		stack<char> s;
		for (auto& c : str)
			s.push(c);

		for (int i = 0; i < str.size(); ++i)
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
}