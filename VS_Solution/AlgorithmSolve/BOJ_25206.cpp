#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	map<string, double> board{
		make_pair("A+", 4.5),
		make_pair("A0", 4.0),
		make_pair("B+", 3.5),
		make_pair("B0", 3.0),
		make_pair("C+", 2.5),
		make_pair("C0", 2.0),
		make_pair("D+", 1.5),
		make_pair("D0", 1.0),
		make_pair("F", 0.0),
		make_pair("P", -1.0)	// 계산 제외.
	};

	double all_credit = 0.0;
	double my_credit = 0.0;

	for (int i = 0; i < 20; ++i)
	{
		string str;
		getline(cin, str);

		istringstream ss(str);
		string stringBuffer;
		vector<string> x;

		while (getline(ss, stringBuffer, ' ')) {
			x.push_back(stringBuffer);
		}

		if (x[2] != "P")
		{
			all_credit += stod(x[1]);	// 학점 총합 더하기
			my_credit += stod(x[1]) * board[x[2]];
		}
	}

	printf("%.6lf\n", my_credit / all_credit);
}