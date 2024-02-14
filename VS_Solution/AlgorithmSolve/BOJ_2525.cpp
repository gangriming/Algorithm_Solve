#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int hour, min, c;
	cin >> hour >> min >> c;

	auto plustime = min + c;
	hour += plustime / 60;
	min = plustime % 60;
	hour %= 24;

	cout << hour << " " << min << "\n";
}