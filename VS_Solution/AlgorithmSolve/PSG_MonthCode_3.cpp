#include <string>
#include <vector>
#include <iostream>

using namespace std;

/*
각 점에 가중치가 부여된 트리가 주어집니다.
당신은 다음 연산을 통하여,
이 트리의 모든 점들의 가중치를 0으로 만들고자 합니다.

임의의 연결된 두 점을 골라서 한쪽은 1 증가시키고,
다른 한쪽은 1 감소시킵니다.

하지만, 모든 트리가 위의 행동을 통하여
모든 점들의 가중치를 0으로 만들 수 있는 것은 아닙니다.
당신은 주어진 트리에 대해서 해당 사항이 가능한지 판별하고,
만약 가능하다면 최소한의 행동을 통하여
모든 점들의 가중치를 0으로 만들고자 합니다.
*/

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;

    // 조건 1
    // - 무조건 가중치를 다 더했을때, 짝수가 되어야 함.
    int sum = 0;
    for (const auto value : a)
        sum += value;
    if (sum % 2 == 1)
        return -1;

    // 그리디? 그리디로 풀면 최소 숫자를 구할 수 없을 듯.
    // 0인것은 최대한 건드리면 안된다. 


    return answer;
}

int main()
{
    cout << solution(vector<int>{-5, 0, 2, 1, 2}, vector<vector<int>>{ {0, 1}, { 3, 4 }, { 2, 3 }, { 0, 3 }}) << endl;
}
