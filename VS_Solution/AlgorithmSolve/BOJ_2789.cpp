#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	string cam = "CAMBRIDGE";

	string check;
	cin >> check;

	string answer;
	for (int i = 0; i < check.length(); ++i)
	{
		auto c = check[i];
		bool flag = true;
		for (int j = 0; j < cam.length(); ++j)
		{
			if (c == cam[j])
			{
				flag = false;
				break;
			}
		}
		
		if (flag)
			answer += c;
	}

	cout << answer << endl;
}
