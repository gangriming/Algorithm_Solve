#include <iostream>
#include <cmath>


using namespace std;

int main()
{
	
	int maxscore = -1;
	int idx = -1;
	int sum = -1;

	for (int i = 1; i <= 5; ++i)
	{
		int score = 0;
		sum = 0;

		for (int j = 0; j < 4; ++j)
		{
			cin >> score;
			sum += score;
		}

		if (sum > maxscore)
		{
			maxscore = sum;
			idx = i;
		}
	}

	cout << idx << " " << maxscore << endl;
}