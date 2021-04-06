#include <iostream>

using namespace std;


int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int mindiff = 9999;
	
	if (mindiff > abs(w - x))
		mindiff = abs(w - x);
	if(mindiff > abs(h - y))
		mindiff = abs(h - y);

	if (mindiff > x)
		mindiff = x;
	if (mindiff > y)
		mindiff = y;

	cout << mindiff << endl;

}