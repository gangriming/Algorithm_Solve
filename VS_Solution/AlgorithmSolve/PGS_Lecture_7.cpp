#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end(), greater<vector<string>>());    // �������� ǥ�� �����Ѵ�.

    unordered_map<string, vector<string>> routes;  
    for (int i = 0; i < tickets.size(); ++i)
    {
        routes[tickets[i][0]].push_back(tickets[i][1]);    // ��� ������ Ű��, ���� ������ vector��
    }

    vector<string> s = vector<string>{ "ICN" }; // ����� ������ ��õ�̴ϱ�, ���ÿ� �־��ش�.
    while (!s.empty())
    {
        string airport = s.back(); // ���� ���߿� �� ����
        if (routes.find(airport) == routes.end() ||   // �� �������κ��� ����ϴ� ǥ�� ���ų�
            routes[airport].size() == 0)    // ǥ�� �� ����� ���
        {
            // �� ���׿��� ���̻� �� ���� ����.
            answer.push_back(airport);
            s.pop_back();   // ���ÿ��� ����
        }
        else // �� ���׿��� �� ���� �ִ� ���
        {
            s.push_back(routes[airport].back());    // ������ �������� �Ǿ��־ �ں��� ������ ���ĺ������� ����.
            routes[airport].pop_back();
        }
    }

    reverse(answer.begin(), answer.end());
    return answer;
}


int main()
{
    solution(vector<vector<string>> { {"ICN", "JFK"}, { "HND", "IAD" }, { "JFK", "HND" }});
    cout << endl;
    solution(vector<vector<string>> { {"ICN", "SFO"}, { "ICN", "ATL" }, { "SFO", "ATL" }, { "ATL", "ICN" }, { "ATL", "SFO" }});
    cout << endl;
    solution(vector<vector<string>> { {"ICN", "A"}, { "A", "B" }, { "A", "C" }, { "C", "A" }, { "B", "D" }});
}