#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string str;
	cin >> str;
	
	string temp;
	for (int i = str.size() - 1; i >= 0; --i)
		temp += str[i];

	if (str == temp)
		cout << "1\n";
	else
		cout << "0\n";

}