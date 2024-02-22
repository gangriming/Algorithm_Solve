#include <iostream>
#include <map>

using namespace std;


static map<int, long long> save;

static long long recurrence(int n)
{
	if (n < 2)
		return 1;
	else if (save[n] > 0)
		return save[n];
	else
	{
		long long sum = 0;

		for (int i = 0; i < n; ++i)
		{
			sum += recurrence(i) * recurrence(n - (i + 1));
		}
		save[n] = sum;
	}
	return save[n];
}

int main()
{
	int n;
	cin >> n;

	cout << recurrence(n) << endl;
	

}
