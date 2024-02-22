#include <iostream>
#include <string>

using namespace std;

int main()
{
	string phone1;
	string phone2;

	cin >> phone1 >> phone2;

	string newphone;
	for (int i = 0; i < 8; ++i)
	{
		newphone += phone1[i];
		newphone += phone2[i];
	}
	do
	{
		string temp;

		for (int i = 0; i < newphone.length()-1; ++i)
		{
			//auto num1 = (atoi(&newphone[i]) + atoi(&newphone[i + 1])) % 10;
			auto num1 = stoi(newphone.substr(i, 1));
			auto num2 = stoi(newphone.substr(i+1, 1));
			temp += to_string((num1 + num2) % 10);
		}

		newphone = temp;

	} while (newphone.length() > 2);

	cout << newphone << endl;

}