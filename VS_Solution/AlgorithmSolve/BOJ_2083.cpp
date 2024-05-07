#include <iostream>
#include <string>

using namespace std;

int main()
{
	while (true)
	{
		string name;
		int age, weight;
		cin >> name >> age >> weight;

		if (name[0] == '#')
			return 0;

		cout << name << " ";

		if (age > 17 || weight >= 80)
			cout << "Senior\n";
		else
			cout << "Junior\n";
	}
}