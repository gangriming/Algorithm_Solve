#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;

    // 5킬로그램 봉지부터 사용하면서 최소 개수의 봉지 선택 (3을 선택하면 불리해서)
    while (N > 0) {
        if (N % 5 == 0) {
            count += N / 5;
            N = 0;
        }
        else {
            N -= 3;
            count++;
        }

        // 3킬로그램 봉지로 나누어 떨어지지 않으면 -1 출력
        if (N < 0) {
            count = -1;
            break;
        }
    }

    cout << count << endl;

    return 0;
}