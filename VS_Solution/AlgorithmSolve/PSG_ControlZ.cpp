#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;


int solution(string s)
{
    int answer = 0;
    int prev = 0;
    istringstream ss(s);
    string buff;

    vector<string> v;

    // 문자열 공백 기준으로 자르기.
    while (getline(ss, buff, ' '))
    {
        v.push_back(buff);
    }

    for (auto& value : v)
    {
        if (value[0] == 'Z')
            answer -= prev;
        else
        {
            auto toint = atoi(value.c_str());
            answer += toint;
            prev = toint;
        }
    }
    return answer;
}



int main()
{

}