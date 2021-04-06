#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    // �� ����� �� ���� ������(���Ʈ ����..) Ž��� �з��ϱ� ������ �غ���.
    // ���Ʈ ������ O(N!)�ƴѰ�?
    // ���ڸ��� ū ���� ���°��� ��ü�� ũ�� �����. ����, ū ���� ��, �������� ��(k�� ����)

    for (int i = 0; i < number.size(); ++i)
    {
        if (k == 0)
            answer += number[i];        // Ƚ���� ���ٸ� �׳� �ִ´�.
        else
        {
            // �� �� �ִ� Ƚ���� ���Ҵٸ�
            if (!answer.empty()) // ���ڿ��� �����Ѵٸ�
            {
                while (k != 0 && !answer.empty())
                {
                    if (answer[answer.size() - 1] < number[i]) // ���� ������ ���� �� ũ��
                    {
                        answer.pop_back();  // ���� ���� ������ �ڸ� ����.
                        k--;
                    }
                    else
                        break;
                }
                answer.push_back(number[i]);
            }
            else    // ������ �׳� �־���
                answer.push_back(number[i]);

        }
    }

    return answer;
}



int main()
{
   cout <<  solution("1924", 2) << endl;
}