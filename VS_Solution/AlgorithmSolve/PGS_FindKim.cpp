#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

string solution(vector<string> seoul) {
    string answer = "�輭���� ";

    auto f = find(seoul.begin(), seoul.end(), "Kim");
    answer += distance(seoul.begin(), f);
    answer += "�� �ִ�";

    return answer;
}

int main()
{
    cout << solution(vector<string>{"Jane", "Kim"}) << endl;
}