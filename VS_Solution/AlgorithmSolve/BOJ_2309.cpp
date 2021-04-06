#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int tall[9];
	for (int i = 0; i < 9; ++i)
		cin >> tall[i];

	int sum = 0;
	for (int i = 0; i < 9; ++i)
		sum += tall[i];

	int error = sum - 100;
	vector<int> fairy;
	bool isTrue = false;
	
	for (int i = 0; i < 8; ++i)
	{
		if (tall[i] >= error)
			continue;

		int j = i + 1;
		while (j != 9)
		{
			if (tall[i] + tall[j] == error)	// 난쟁이가 아닌 애들
			{
				for (int k = 0; k < 9; ++k)
				{
					if (tall[k] != tall[i] && tall[k] != tall[j])
					{
						fairy.push_back(tall[k]);
					}
				}
				isTrue = true;
				break;
			}
			else
			{
				++j;
				continue;
			}
		}

		if (isTrue)
			break;

		//if (i == 7)
		//{
		//	if (tall[i] + tall[8] == error)	// 난쟁이가 아닌 애들
		//	{
		//		for (int k = 0; k < 9; ++k)
		//		{
		//			if (tall[k] != tall[i] && tall[k] != tall[8])
		//			{
		//				fairy.push_back(tall[k]);
		//			}
		//		}
		//		isTrue = true;
		//		break;
		//	}
		//}
	}

	//system("cls");

	sort(fairy.begin(), fairy.end());

	for (int i = 0; i < fairy.size(); ++i)
		cout << fairy[i] << endl;
}