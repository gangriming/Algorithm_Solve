#include <string>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;


    for (int i = 0; i < s.length(); ++i)
    {
        stack<char> cs;

        string first = s.substr(0, 1);
        string sub = s.substr(1, s.length() - 1);
        s = sub + first ;
        // s는 회전된 문자열이 된다. 마지막이 원형

        bool flag = true;   // 중간에 나오는거 방지

        for (const auto& value : s)
        {
            if (value == '[' || value == '(' || value == '{')
            {
                cs.push(value);
            }
            else    // 닫는거면
            {
                if (cs.empty())
                {
                    flag = false;
                    break;
                }
                if (value == ']' && cs.top() == '[')
                    cs.pop();
                else if (value == ')' && cs.top() == '(')
                    cs.pop();
                else if (value == '}' && cs.top() == '{')
                    cs.pop();
                else
                {
                    flag = false;
                    break;
                }
            }
        }

        if (cs.empty() && flag)
            answer++;
    }
    return answer;
}

int main()
{
    cout << solution("[](){}") << endl;
    cout << solution("}]()[{") << endl;
    cout << solution("[)(]") << endl;
    cout << solution("}}}") << endl;
}