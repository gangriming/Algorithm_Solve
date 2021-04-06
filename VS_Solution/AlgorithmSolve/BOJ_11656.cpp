#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	multiset<string> s;

	for (int i = 0; i < str.length(); ++i)
		s.insert(str.substr(i, str.length()));

	for (const auto& value : s)
		cout << value << endl;

}