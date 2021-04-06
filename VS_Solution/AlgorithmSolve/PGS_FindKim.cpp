#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";

    auto f = find(seoul.begin(), seoul.end(), "Kim");
    answer += distance(seoul.begin(), f);
    answer += "에 있다";

    return answer;
}

int main()
{
    cout << solution(vector<string>{"Jane", "Kim"}) << endl;
}