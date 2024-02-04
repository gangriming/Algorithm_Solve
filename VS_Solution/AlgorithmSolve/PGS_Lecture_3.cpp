#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 비교함수를 만들어서 문제 확인하기.
bool compare(int a, int b)
{
	string s1 = to_string(a) + to_string(b);
	string s2 = to_string(b) + to_string(a);

	return s1 > s2;
}

string solution(vector<int> numbers)
{
	string answer = "";

	sort(numbers.begin(), numbers.end(), compare);	// O(nlogn)
	for (auto& value : numbers)
		answer += to_string(value);

	//return answer;
	return answer[0] == '0' ? "0" : answer;	// 0인경우에, 0000이렇게 될 경우 방지.
}

int main()
{


}