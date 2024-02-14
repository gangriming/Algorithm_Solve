#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;

	unordered_map<string, int> book;

	while (n--)
	{
		string str;
		cin >> str;
		
		book[str]++;
	}

	auto max_element = std::max_element(book.begin(), book.end(),
		[](const auto& pair1, const auto& pair2) {
			return pair1.second < pair2.second;
		}
	)->second;

	string number1 = "~";
	for (const auto& pair : book)
	{
		if (pair.second == max_element && number1 > pair.first)
		{
			number1 = pair.first;
		}
	}
	cout << number1 << endl;
}