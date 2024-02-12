#include <string>
#include <vector>
#include <queue>

using namespace std;

// �� .
//int solution(vector<int> scoville, int K) {
//    int answer = 0;
//
//    priority_queue<unsigned int, vector<unsigned int>, greater<>> pq(scoville.begin(), scoville.end());
//
//    while (pq.size() > 1)
//    {
//        auto mix_1 = pq.top(); pq.pop();
//        auto mix_2 = pq.top(); pq.pop();
//
//        auto mix_final = mix_1 + mix_2 * 2;
//        pq.push(mix_final);
//        answer++;
//        if (mix_final >= K)
//            break;
//    }
//
//    if (pq.empty() && pq.top() < K) {
//        // ��� ������ ��� K �̻��� ���� ���� ���
//        return -1;
//    }
//
//    return answer;
//}


// ����
int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    // less<>�̸� max_heap, greater<>�� min_heap
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());   // O(NLogN)

    while (1) // �־��� ��� N-1ȸ �ݺ�.
    {
        // ���� ������ O(logN)
        int min_1 = pq.top(); pq.pop();
        if (min_1 >= K)
            break;
        else if (pq.empty())
            return -1;  // ��� �Ұ����� ��. 

        int min_2 = pq.top(); pq.pop();
        pq.push(min_1 + min_2 * 2); // ������ �־��ش�.
        answer++;   // �ѹ� ������.
    }
    return answer;
}

int main()
{
    solution(vector<int>{1, 2, 3, 4}, 100);
}