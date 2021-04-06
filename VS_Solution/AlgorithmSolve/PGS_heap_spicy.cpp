#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    // ȿ���� ����ϱ�.
    // ��(Heap)�� ���� ������, O(n^2)���� ������ �� �ִ� ������.

    // �ּ�, �ִ� ���Ҹ� ������ ���� �� ������ ���� ��. <- Heap(Max / Min)
    // ����, ���� O(logN).. ���� ���� Ʈ�� ����(�迭�� ���� ����), �� �����ÿ� O(NlogN)
    // ���� ���� - ����(heap sort), �켱 ���� ť(�켱������ �������� ���� ��������)

    priority_queue<int, vector<int>, greater<int>> q;
    for (const auto& value : scoville)
        q.push(value);

    while (true)
    {
        if (q.top() >= K)   // ��� ���ں� K�� ����
            break;
        else
        {
            if (q.size() < 2)    // �� ���� �� ������
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