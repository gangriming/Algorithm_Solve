#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    /*
    for (int i = 0; i < skill_trees.size(); ++i)
    {
        string str = skill;

        int idx = skill_trees[i].find(str[0]);
        int preIdx = -1;

        if (idx == -1)
        {
            // 처음부터 없다면 아예 존재하지 않아서 배울 수 있는지 살펴봐야된다.
            bool flag = true;
            for (int j = 1; j < str.length(); ++j)
            {
                if (-1 == skill_trees[i].find(str[j]))
                    continue;
                else    // 있으면
                    flag = false;
                break;
            }
            if (flag)
                answer++;
        }
        else
        {
            str.erase(str.begin());
            while (!str.empty())
            {
                idx = skill_trees[i].find(str[0], idx);
                if (idx == -1)
                    break;
                else
                    str.erase(str.begin());
                preIdx = idx;
            }
            if (str.empty()) // 비었거나, 중간에 끊긴게 아니어야함.
                answer++;
            else if (!str.empty() && preIdx == skill_trees[i].length() - 1)
            {
                bool flag = true;
                for (int j = 0; j < str.length(); ++j)
                {
                    if (-1 == skill_trees[i].find(str[j]))
                        continue;
                    else    // 있으면
                        flag = false;
                    break;
                }
                if (flag)
                    answer++;
            }
            else if (skill_trees[i].size() == 1)
                answer++;
        }
    }
    */

    for (const auto& tree : skill_trees)
    {
        vector<char> seq;

        for (int i = 0; i < tree.length(); ++i)
        {
            // 1. 유저의 skilltree를 돌면서 선행스킬이 있는지 확인한다.
            // 2. 있으면 그것이 선행스킬의 가장 앞 인덱스인지 확인한다.
            // 3. 아니라면 false
            // 4. 선행스킬을 다 소모하면 true
            // 5. 선행스킬이 하나도 없다면 true
            for (int j = 0; j < skill.length(); ++j)
            {
                if (tree[i] == skill[j])
                    seq.push_back(skill[j]);
            }
        }

        bool flag = true;
        for (int i = 0; i < seq.size(); ++i)        // 선행트리와 순서가 맞는지 맞추어본다.
        {
            if (skill[i] != seq[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
            answer++;
    }

    return answer;
}
int main()
{
    solution("CBD", vector<string>{"C", "D", "CB", "BDA"});
}