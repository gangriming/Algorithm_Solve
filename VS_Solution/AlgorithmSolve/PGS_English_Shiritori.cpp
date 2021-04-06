#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    set<string> s;
    int count = 1;
    s.insert(words[0]);

    for (int i = 1; i < words.size(); ++i)
    {
        ++count;
        auto flag = s.insert(words[i]);
        if (!flag.second)   // 중복 값을 말했을 경우
        {
            if (count % n == 0)
                answer.push_back(n);
            else
                answer.push_back(count % n);
            answer.push_back(ceil(float(count) / float(n)));
            break;
        }
        else // 중복 값이 아니면
        {
            if (words[i - 1].back() != words[i].front()) // 이어지지 않음
            {
                if (count % n == 0)
                    answer.push_back(n);
                else
                    answer.push_back(count % n);
                answer.push_back(ceil(float(count) / float(n)));
                break;
            }
            else
                continue;
        }
    }

    if (answer.size() < 2)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}

int main()
{
   // solution(3, vector<string>{"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});
    //solution(5, vector<string>{"hello", "observe", "effect", "take", "either", "recognize", "encourage", "ensure", "establish", "hang", "gather", "refer", "reference", "estimate", "executive"});
    solution(2, vector<string>{"hello", "one", "even", "never", "now", "world", "draw"});

}