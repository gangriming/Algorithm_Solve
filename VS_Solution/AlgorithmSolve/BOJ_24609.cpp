#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;
	int need = 0;

	while (n--)
	{
		int temp;
		cin >> temp;
		sum += temp;

		if (sum < need)
			need = sum;
	}


	cout << -need << endl;
}