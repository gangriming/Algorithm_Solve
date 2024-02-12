#include <string>
#include <vector>
#include <queue>

using namespace std;

// 흠 .
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
//        // 모든 음식을 섞어도 K 이상이 되지 않은 경우
//        return -1;
//    }
//
//    return answer;
//}


// 강의
int solution(vector<int> scoville, int K) 
{
    int answer = 0;
    // less<>이면 max_heap, greater<>면 min_heap
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());   // O(NLogN)

    while (1) // 최악의 경우 N-1회 반복.
    {
        // 내부 로직은 O(logN)
        int min_1 = pq.top(); pq.pop();
        if (min_1 >= K)
            break;
        else if (pq.empty())
            return -1;  // 섞어도 불가능할 때. 

        int min_2 = pq.top(); pq.pop();
        pq.push(min_1 + min_2 * 2); // 섞은걸 넣어준다.
        answer++;   // 한번 섞었다.
    }
    return answer;
}

int main()
{
    solution(vector<int>{1, 2, 3, 4}, 100);
}