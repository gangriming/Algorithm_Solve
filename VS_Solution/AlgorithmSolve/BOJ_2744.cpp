#include <iostream>
#include <cctype>	// uppercase / lowercase문에 쓰는거.
// islower - tolower , isupper - toupper

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); ++i)
	{
		if (islower(str[i]))
			cout << char(toupper(str[i]));
		else
			cout << char(tolower(str[i]));
	}
}