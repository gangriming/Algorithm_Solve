#include <iostream>
#include <string>

using namespace std;

int main() 
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string str;
	cin >> str;

	int idx = str.find_first_of('*');

	string front_str = str.substr(0, idx);
	string back_str = str.substr(idx + 1);

	while (n--)
	{
		string question;
		cin >> question;

		if (question.length() < front_str.length() + back_str.length())
		{
			cout << "NE\n";
			continue;
		}

		if (question.substr(0, front_str.length()) == front_str &&
			question.substr(question.length() - back_str.length()) == back_str)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
}
