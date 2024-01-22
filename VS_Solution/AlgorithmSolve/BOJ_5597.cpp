#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> student;
	for (int i = 1; i <= 30; ++i)
		student.push_back(i);

	for (int i = 0; i < 28; ++i)
	{
		int homework = 0;
		cin >> homework;

		student[homework - 1] = -1;
	}

	for (int i = 0; i < student.size(); ++i)
	{
		if (student[i] != -1)
		{
			cout << student[i] << endl;
			student[i] = -1;
			break;
		}
	}

	for (int i = 0; i < student.size(); ++i)
	{
		if (student[i] != -1)
		{
			cout << student[i] << endl;
			student[i] = -1;
			break;
		}
	}
}