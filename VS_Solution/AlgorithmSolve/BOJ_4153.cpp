#include <iostream>
#include <algorithm>
using namespace std;

bool isRightTriangle(int a, int b, int c) {
    // 가장 긴 변이 빗변이 되도록 정렬
    int sides[3] = { a, b, c };
    sort(sides, sides + 3);
    int a_squared = sides[0] * sides[0];
    int b_squared = sides[1] * sides[1];
    int c_squared = sides[2] * sides[2];

    // 피타고라스의 정리 확인
    return a_squared + b_squared == c_squared;
}

int main() {
    while (true) {
        // 입력 받기
        int a, b, c;
        cin >> a >> b >> c;

        // 입력의 끝 확인
        if (a == 0 && b == 0 && c == 0)
            break;

        // 직각 삼각형인지 확인하여 출력
        if (isRightTriangle(a, b, c))
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}
