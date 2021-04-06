#include <iostream>

using namespace std;

int main()
{
	int level = 0;
	cin >> level;

	short score[100];

	for (int i = 0; i < level; ++i)
	{
		int temp = 0;
		cin >> temp;
		score[i] = temp;
	}

	int count = 0;

	//for (int i = 1; i < level; ++i)
	//{
	//	if (score[i] <= score[i - 1])
	//	{
	//		while (score[i] <= score[i - 1])
	//		{
	//			--score[i - 1];
	//			++count;
	//		}
	//	}
	//}

	for (int i = level - 1; i > 0; --i)
	{
		if (score[i] <= score[i - 1])
		{
			while (score[i] <= score[i - 1])
			{
				--score[i - 1];
				++count;
			}
		}
	}

	cout << count << endl;
}