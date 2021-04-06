#include <iostream>
#include <vector>

using namespace std;

struct info
{
	info() {};
	info(int connect) { this->connect = connect; }

	int connect = -1;
	bool visit = false;
	int count = 1;
};

int main()
{
	int n = 0;
	cin >> n;

	vector<info> people;
	people.reserve(n);

	for (int i = 0; i < n; ++i)
	{
		int temp = 0;
		cin >> temp;
		people.push_back(info(temp));
	}

	int maxCount = -1;
	int maxIndex = -1;

	for (int i = 0; i < n; ++i)
	{
		int temp = i;

		while (true)
		{
			if (people[temp].visit)
				break;

			// connect를 1 줄여서 연결하기.
			people[temp].visit = true;
			temp = people[temp].connect-1;	// 다음 선배로 감.
			people[i].count++;

			if (people[i].count > maxCount)
			{
				maxCount = people[i].count;
				maxIndex = i + 1;
			}
		}

		for (int j = 0; j < people.size(); ++j)
			people[j].visit = false;
	}

	cout << maxIndex << endl;

}