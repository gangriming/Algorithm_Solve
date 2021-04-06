#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    /*
    동적 계획법(다이나믹 프로그래밍) = 알고리즘 진행에 따라, 탐색해야 할 범위를 동적으로 결정한다.
    주어진 최적화 문제를
        재귀적인 방식으로 보다 작은 부분 문제로 나누어
        부분 문제를 풀어, 이 해를 조합하여 (분할 정복 느낌?)
        전체 문제의 해답에 이르는 방식
    Ex) 피보나치 수열, Knapsack Problem
    */

    /*
    N을 한번 사용해서 만들 수 있는 수 ..
    두번..
    세번..
    N = 5일때
    1번 사용 - 5
    2번 사용 - 55, 10, 0, 25, 1
    3번 사용 - 555 ...... 하고 [1번(+-X/)2번], [2번(+-X/)1번]
    4번 사용 - 5555 ...... 와 [1번(연산)3번], [2번(연산)2번], [3번(연산)1번]..
    5번 사용 - 55555 ..... 와 [1번 4번], [2번 3번], [3번 2번], [4번 1번]...
    물론 중복은 제외한다.
    */

    /*
    문제의 성질에 따라, 동적 계획법으로 품으로써 탐색 범위를 효과적으로 줄일 수 있다.
    이건 파훼법이 없음.......................
    */
    
    unordered_set<int> s[8];

    int base = 0;
    for (int i = 0; i < 8; ++i)
    {
        base = 10 * base + 1;
        s[i].insert(base * N);
    }

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (auto& op1 : s[j])    // 왼쪽
            {
                for (auto& op2 : s[i - j - 1])    // 오른쪽
                {
                    // 사칙연산 해서 넣어준다.
                    s[i].insert(op1 + op2);
                    s[i].insert(op1 - op2);
                    s[i].insert(op1 * op2);
                    if(op2 != 0)
                        s[i].insert(op1 / op2);
                }
            }
        }
        if (s[i].count(number) > 0)
        {
            answer = i + 1;
            break;
        }
    }
    return answer;
}