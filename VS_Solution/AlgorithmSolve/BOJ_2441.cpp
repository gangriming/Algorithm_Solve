#include <iostream>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int star = 0;
	int blank = 0;
	cin >> star;

	// �� ������ �����ؼ� ���

	while (star)
	{
		for(int i = 0 ; i < blank ; ++i)
			cout << " ";

		for (int i = 0; i < star; ++i)
			cout << "*";

		cout << endl;
		--star;
		++blank;
	}

	return 0;
}