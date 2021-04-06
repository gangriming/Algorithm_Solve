#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    stack<int> s;
    for (int i = prices.size() - 1; i >= 0; --i)
        s.push(prices[i]);

    while (answer.size() != prices.size())
    {
        int price = s.top();
        s.pop();

        cout << "Ž���� : " << price << endl;

        int size = s.size();

        vector<int> v;

        if (size == 0)
        {
            answer.push_back(0);
            break;
        }
        else
        {
            for (int i = 1; i <= size; ++i)
            {
                if (price <= s.top())    // ������ �������� ����
                {
                    cout << price << "���� �ȶ�����" << endl;
                    v.push_back(s.top());
                    s.pop();
                }
                else
                {
                    answer.push_back(i);
                }
            }
            for (int i = v.size() - 1; i >= 0; --i)
                s.push(v[i]);
            // ������ ������ �ȶ����� ���
            if (v.size() == s.size())
                answer.push_back(v.size());

        }
    }

    return answer;
}