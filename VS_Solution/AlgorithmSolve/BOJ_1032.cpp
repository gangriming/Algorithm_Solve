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
	string answer;

	for(int i = 0 ; i < n ; ++i)
	{
		cin >> str;
		// 최초엔 저장.
		if (i == 0)
		{
			answer = str;
			continue;
		}

		for (int j = 0; j < answer.length(); ++j)
		{
			if (answer[j] != str[j])
				answer[j] = '?';
		}
	}

	cout << answer << endl;

}