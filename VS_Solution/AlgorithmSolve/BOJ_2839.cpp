#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;

    // 5ų�α׷� �������� ����ϸ鼭 �ּ� ������ ���� ���� (3�� �����ϸ� �Ҹ��ؼ�)
    while (N > 0) {
        if (N % 5 == 0) {
            count += N / 5;
            N = 0;
        }
        else {
            N -= 3;
            count++;
        }

        // 3ų�α׷� ������ ������ �������� ������ -1 ���
        if (N < 0) {
            count = -1;
            break;
        }
    }

    cout << count << endl;

    return 0;
}