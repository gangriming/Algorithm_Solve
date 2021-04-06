#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // 효율성 고려하기.
    // 힙(Heap)을 쓰지 않으면, O(n^2)으로 구현할 수 있는 문제다.

    // 최소, 최대 원소를 빠르게 꺼낼 수 있으면 좋을 때. <- Heap(Max / Min)
    // 삽입, 삭제 O(logN).. 완전 이진 트리 형식(배열로 구현 가능), 힙 구성시엔 O(NlogN)
    // 힙의 응용 - 정렬(heap sort), 우선 순위 큐(우선순위가 높은것이 먼저 빠져나옴)

    priority_queue<int, vector<int>, greater<int>> q;
    for (const auto& value : scoville)
        q.push(value);

    while (true)
    {
        if (q.top() >= K)   // 모두 스코빌 K를 넘음
            break;
        else
        {
            if (q.size() < 2)    // 더 섞을 수 없으면
            {
                answer = -1;
                break;
            }
            else
            {
                int a = q.top();
                q.pop();
                int b = q.top();
                q.pop();

                q.push(a + b * 2);
                answer++;
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution(vector<int>{1, 2, 3, 9, 10, 12}, 7) << endl;
}