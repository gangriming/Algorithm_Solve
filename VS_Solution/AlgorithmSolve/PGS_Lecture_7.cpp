#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    sort(tickets.begin(), tickets.end(), greater<vector<string>>());    // 역순으로 표를 정리한다.

    unordered_map<string, vector<string>> routes;  
    for (int i = 0; i < tickets.size(); ++i)
    {
        routes[tickets[i][0]].push_back(tickets[i][1]);    // 출발 공항을 키로, 가는 공항을 vector로
    }

    vector<string> s = vector<string>{ "ICN" }; // 출발은 무조건 인천이니까, 스택에 넣어준다.
    while (!s.empty())
    {
        string airport = s.back(); // 가장 나중에 들어간 공항
        if (routes.find(airport) == routes.end() ||   // 이 공항으로부터 출발하는 표가 없거나
            routes[airport].size() == 0)    // 표를 다 써버린 경우
        {
            // 이 공항에서 더이상 갈 데가 없다.
            answer.push_back(airport);
            s.pop_back();   // 스택에서 제거
        }
        else // 이 공항에서 갈 데가 있는 경우
        {
            s.push_back(routes[airport].back());    // 정렬이 역순으로 되어있어서 뒤부터 넣으면 알파벳순으로 간다.
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