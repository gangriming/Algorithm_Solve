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

        cout << "탐색중 : " << price << endl;

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
                if (price <= s.top())    // 가격이 떨어지지 않음
                {
                    cout << price << "가격 안떨어짐" << endl;
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
            // 가격이 끝까지 안떨어진 경우
            if (v.size() == s.size())
                answer.push_back(v.size());

        }
    }

    return answer;
}