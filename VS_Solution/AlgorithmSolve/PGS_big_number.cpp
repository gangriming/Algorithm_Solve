#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    // 다 만들어 볼 수도 있지만(브루트 포스..) 탐욕법 분류니까 생각을 해보기.
    // 브루트 포스는 O(N!)아닌가?
    // 앞자리에 큰 수가 오는것이 전체를 크게 만든다. 따라서, 큰 수를 앞, 작은수는 뒤(k개 내로)

    for (int i = 0; i < number.size(); ++i)
    {
        if (k == 0)
            answer += number[i];        // 횟수가 없다면 그냥 넣는다.
        else
        {
            // 뺄 수 있는 횟수가 남았다면
            if (!answer.empty()) // 문자열이 존재한다면
            {
                while (k != 0 && !answer.empty())
                {
                    if (answer[answer.size() - 1] < number[i]) // 지금 들어오는 수가 더 크면
                    {
                        answer.pop_back();  // 지금 넣은 숫자중 뒤를 뺀다.
                        k--;
                    }
                    else
                        break;
                }
                answer.push_back(number[i]);
            }
            else    // 없으면 그냥 넣어줌
                answer.push_back(number[i]);

        }
    }

    return answer;
}



int main()
{
   cout <<  solution("1924", 2) << endl;
}