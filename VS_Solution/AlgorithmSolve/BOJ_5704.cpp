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
		getline(cin, str);

		if (str.length() == 1 && str[0] == '*')
			return 0;

		bool check[26] = { false, };

		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] == ' ')
				continue;

			auto c = str[i];
			int j = str[i] - 97;

			check[j] = true;
		}

		bool flag = true;
		for(int i = 0 ; i < 26 ; ++i)
		{
			if (check[i] == false)
			{
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "Y\n";
		else
			cout << "N\n";
	}
}