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

    // 가능한 모든 3장의 카드 조합을 확인
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int sum = v[i] + v[j] + v[k];
                // 주어진 값 M을 넘지 않으면서 최대한 가까운 값을 찾음
                if (sum <= m) {
                    max_sum = max(max_sum, sum);
                }
            }
        }
    }

    cout << max_sum << endl;

}