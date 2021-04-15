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
        // s�� ȸ���� ���ڿ��� �ȴ�. �������� ����

        bool flag = true;   // �߰��� �����°� ����

        for (const auto& value : s)
        {
            if (value == '[' || value == '(' || value == '{')
            {
                cs.push(value);
            }
            else    // �ݴ°Ÿ�
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