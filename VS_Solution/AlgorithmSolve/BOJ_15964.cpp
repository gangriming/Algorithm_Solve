#include <iostream>
#include <string>

using namespace std;

long long hyojin(int a, int b)
{
	long long c = a + b;
	long long d = a - b;
	return c * d;
}


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b = 0;
	cin >> a >> b;

	cout << hyojin(a, b) << endl;

	return 0;
}