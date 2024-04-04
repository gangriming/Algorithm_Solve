#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v(n, 0);

	for (int i = 0; i < n; ++i)
		cin >> v[i];

    int max_sum = 0;

    // ������ ��� 3���� ī�� ������ Ȯ��
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int sum = v[i] + v[j] + v[k];
                // �־��� �� M�� ���� �����鼭 �ִ��� ����� ���� ã��
                if (sum <= m) {
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }

    cout << max_sum << endl;

}