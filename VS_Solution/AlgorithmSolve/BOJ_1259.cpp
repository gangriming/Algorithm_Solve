#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true)
	{
		string str;
		cin >> str;

		if (str == "0")
			return 0;

		string temp;
		for (int i = str.length() - 1; i >= 0; --i)
			temp += str[i];

		if (str == temp)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}