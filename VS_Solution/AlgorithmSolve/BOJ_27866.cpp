#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int at = 0;

	cin >> str >> at;

	cout << str.at(at-1) << endl;
}