#include <iostream>
#include <set>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	set<long> s;

	int n;
	cin >> n;
	while (n--)
	{
		long i = 0;
		cin >> i;

		s.insert(i);
	}

	cin >> n;
	while (n--)
	{
		long i = 0;
		cin >> i;
		if (s.end() != s.find(i))
			cout << "1 ";
		else
			cout << "0 ";
	}

}
