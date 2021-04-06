#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    deque<int> p(progresses.begin(), progresses.end());
    deque<int> s(speeds.begin(), speeds.end());

    while (p.size())
    {
        if (p[0] >= 100)
        {
            int temp = 1;
            p.pop_front();
            s.pop_front();

            while (!p.empty() && p[0] > 100)
            {
                p.pop_front();
                s.pop_front();
                temp++;
            }
            answer.push_back(temp);
        }

        for (int i = 0; i < p.size(); ++i)
            p[i] += s[i];
    }

    return answer;
}

int main()
{
    solution(vector<int>{93, 30, 55}, vector<int>{1, 30, 5});
    solution(vector<int>{95, 90, 99, 99, 80, 99}, vector<int>{1, 1, 1, 1, 1, 1});
    solution(vector<int>{100, 50, 34, 25}, vector<int>{1, 1, 1, 1});
}