#include <string>
#include <vector>
#include <iostream>

using namespace std;

void dfs(string start, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer)
{
    string str = "ZZZ";
    int idx = -1;
    for (int i = 0; i < tickets.size(); ++i)
    {
        if (!visit[i] && tickets[i][0] == start && str > tickets[i][1])    // 방문 X, 시작점 == Start, 도착점 빠른 영문
        {
            str = tickets[i][1];
            idx = i;
        }
    }
    
    if (idx != -1)
    {
        cout << str << " ";
        answer.push_back(str);
        visit[idx] = true;
        dfs(str, tickets, visit, answer);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    // 시작 점은 0번의 출발지.
    vector<bool> visit( tickets.size(), false );

    cout << tickets[0][0] << " ";
    answer.push_back(tickets[0][0]);
    dfs(tickets[0][0], tickets, visit, answer);

    //if()

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