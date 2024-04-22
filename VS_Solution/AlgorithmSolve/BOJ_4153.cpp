#include <iostream>
#include <algorithm>
using namespace std;

bool isRightTriangle(int a, int b, int c) {
    // ���� �� ���� ������ �ǵ��� ����
    int sides[3] = { a, b, c };
    sort(sides, sides + 3);
    int a_squared = sides[0] * sides[0];
    int b_squared = sides[1] * sides[1];
    int c_squared = sides[2] * sides[2];

    // ��Ÿ����� ���� Ȯ��
    return a_squared + b_squared == c_squared;
}

int main() {
    while (true) {
        // �Է� �ޱ�
        int a, b, c;
        cin >> a >> b >> c;

        // �Է��� �� Ȯ��
        if (a == 0 && b == 0 && c == 0)
            break;

        // ���� �ﰢ������ Ȯ���Ͽ� ���
        if (isRightTriangle(a, b, c))
            cout << "right" << endl;
        else
            cout << "wrong" << endl;
    }
    return 0;
}
