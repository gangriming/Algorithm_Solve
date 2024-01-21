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

	// 별 오른쪽 정렬해서 찍기

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