#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 예전 코드
//string solution(string number, int k) {
//    string answer = "";
//
//    // 다 만들어 볼 수도 있지만(브루트 포스..) 탐욕법 분류니까 생각을 해보기.
//    // 브루트 포스는 O(N!)아닌가?
//    // 앞자리에 큰 수가 오는것이 전체를 크게 만든다. 따라서, 큰 수를 앞, 작은수는 뒤(k개 내로)
//
//    for (int i = 0; i < number.size(); ++i)
//    {
//        if (k == 0)   // 횟수가 없다면 그냥 넣는다.
//        {
//            answer += number.substr(i, number.length() - i);
//            break;
//        }
//        else
//        {
//            // 뺄 수 있는 횟수가 남았다면
//            if (!answer.empty()) // 문자열이 존재한다면
//            {
//                while (k > 0 && !answer.empty())
//                {
//                    if (answer[answer.size() - 1] < number[i]) // 지금 들어오는 수가 더 크면
//                    {
//                        answer.pop_back();  // 지금 넣은 숫자중 뒤를 뺀다.
//                        k--;
//                    }
//                    else
//                        break;
//                }
//                answer.push_back(number[i]);
//            }
//            else    // 없으면 그냥 넣어줌
//                answer.push_back(number[i]);
//        }
//    }
//
//    // 지울 수 있는 갯수가 남으면.
//    if (k > 0)
//        answer.resize(answer.size() - k);   // 그만큼 뒤를 지워준다.
//
//    return answer;
//}

// 강의
string solution(string number, int k) {
    string s = "";

    // 처음부터 쭉 적용해도, 최적해가 되는 문제이기때문에 돌릴 수 있음.
    for (int i = 0; i < number.length(); ++i)
    {
        while (!s.empty()   // 원소가 하나라도 있고
            && s.back() < number[i] // 그 맨 끝 문자가, 지금 문자열의 문자보다 작으면
            && k > 0)    // 그리고 빼낼 수 있는 문자갯수가 남아있으면
        {
            s.pop_back();
            k--;
        }

        // 뺄 수 있는 숫자를 다 뺐다면
        if (k == 0)
        {
            // 문자열에 지금까지 있는 문자들을 다 이어붙이고 끝낸다.
            s += number.substr(i, number.length() - i);
            break;
        }
        s.push_back(number[i]);
    }

    // 만약에, 정렬이 잘 되어있어서 k의 소모가 잘 되지 않았을 경우를 대비
    return s.substr(0, s.length() - k);
}


int main()
{
    solution("1924", 2);
    solution("1231234", 3);
    solution("4177252841", 4);
}