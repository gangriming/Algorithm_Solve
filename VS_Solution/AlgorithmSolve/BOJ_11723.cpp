#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);

	int m = 0;
	cin >> m;

	auto bit = bitset<20>();

	while (m)
	{
		//string str = "";
		//getline(cin, str);

		//if (str.empty())
		//	continue;

		//istringstream iss(str);
		string command = "";
		int number = 0;

		cin >> command;
		if (command.empty())
			continue;

		if (command == "add" || command == "remove" || command == "check" || command == "toggle")
			cin >> number;

		if (command == "add")
		{
			bit[number-1] = 1;
		}
		else if (command == "remove")
		{
			bit[number-1] = 0;
		}
		else if (command == "check")
		{
			cout << bit[number-1] << "\n";
		}
		else if (command == "toggle")
		{
			bit.flip(number-1);
		}
		else if (command == "all")
		{
			bit.set();
		}
		else if (command == "empty")
		{
			bit.reset();
		}

		m--;
	}

}
