#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// ���� �ڵ�
//string solution(string number, int k) {
//    string answer = "";
//
//    // �� ����� �� ���� ������(���Ʈ ����..) Ž��� �з��ϱ� ������ �غ���.
//    // ���Ʈ ������ O(N!)�ƴѰ�?
//    // ���ڸ��� ū ���� ���°��� ��ü�� ũ�� �����. ����, ū ���� ��, �������� ��(k�� ����)
//
//    for (int i = 0; i < number.size(); ++i)
//    {
//        if (k == 0)   // Ƚ���� ���ٸ� �׳� �ִ´�.
//        {
//            answer += number.substr(i, number.length() - i);
//            break;
//        }
//        else
//        {
//            // �� �� �ִ� Ƚ���� ���Ҵٸ�
//            if (!answer.empty()) // ���ڿ��� �����Ѵٸ�
//            {
//                while (k > 0 && !answer.empty())
//                {
//                    if (answer[answer.size() - 1] < number[i]) // ���� ������ ���� �� ũ��
//                    {
//                        answer.pop_back();  // ���� ���� ������ �ڸ� ����.
//                        k--;
//                    }
//                    else
//                        break;
//                }
//                answer.push_back(number[i]);
//            }
//            else    // ������ �׳� �־���
//                answer.push_back(number[i]);
//        }
//    }
//
//    // ���� �� �ִ� ������ ������.
//    if (k > 0)
//        answer.resize(answer.size() - k);   // �׸�ŭ �ڸ� �����ش�.
//
//    return answer;
//}

// ����
string solution(string number, int k) {
    string s = "";

    // ó������ �� �����ص�, �����ذ� �Ǵ� �����̱⶧���� ���� �� ����.
    for (int i = 0; i < number.length(); ++i)
    {
        while (!s.empty()   // ���Ұ� �ϳ��� �ְ�
            && s.back() < number[i] // �� �� �� ���ڰ�, ���� ���ڿ��� ���ں��� ������
            && k > 0)    // �׸��� ���� �� �ִ� ���ڰ����� ����������
        {
            s.pop_back();
            k--;
        }

        // �� �� �ִ� ���ڸ� �� ���ٸ�
        if (k == 0)
        {
            // ���ڿ��� ���ݱ��� �ִ� ���ڵ��� �� �̾���̰� ������.
            s += number.substr(i, number.length() - i);
            break;
        }
        s.push_back(number[i]);
    }

    // ���࿡, ������ �� �Ǿ��־ k�� �Ҹ� �� ���� �ʾ��� ��츦 ���
    return s.substr(0, s.length() - k);
}


int main()
{
    solution("1924", 2);
    solution("1231234", 3);
    solution("4177252841", 4);
}