#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> u(9, 0);
	vector<int> s(9, 0);

	for (int i = 0; i < 9; ++i)
		cin >> u[i];

	for (int i = 0; i < 9; ++i)
		cin >> s[i];

	int u_sum = 0;
	int s_sum = 0;
	bool turnaround = false;

	for (int i = 0; i < 9; ++i)
	{
		u_sum += u[i];

		if (u_sum > s_sum)
		{
			turnaround = true;
			break;
		}
		s_sum += s[i];
	}

	if (turnaround)
		cout << "Yes\n";
	else
		cout << "No\n";
}