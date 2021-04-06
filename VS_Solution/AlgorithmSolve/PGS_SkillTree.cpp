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
            // ó������ ���ٸ� �ƿ� �������� �ʾƼ� ��� �� �ִ��� ������ߵȴ�.
            bool flag = true;
            for (int j = 1; j < str.length(); ++j)
            {
                if (-1 == skill_trees[i].find(str[j]))
                    continue;
                else    // ������
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
            if (str.empty()) // ����ų�, �߰��� ����� �ƴϾ����.
                answer++;
            else if (!str.empty() && preIdx == skill_trees[i].length() - 1)
            {
                bool flag = true;
                for (int j = 0; j < str.length(); ++j)
                {
                    if (-1 == skill_trees[i].find(str[j]))
                        continue;
                    else    // ������
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
            // 1. ������ skilltree�� ���鼭 ���ེų�� �ִ��� Ȯ���Ѵ�.
            // 2. ������ �װ��� ���ེų�� ���� �� �ε������� Ȯ���Ѵ�.
            // 3. �ƴ϶�� false
            // 4. ���ེų�� �� �Ҹ��ϸ� true
            // 5. ���ེų�� �ϳ��� ���ٸ� true
            for (int j = 0; j < skill.length(); ++j)
            {
                if (tree[i] == skill[j])
                    seq.push_back(skill[j]);
            }
        }

        bool flag = true;
        for (int i = 0; i < seq.size(); ++i)        // ����Ʈ���� ������ �´��� ���߾��.
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