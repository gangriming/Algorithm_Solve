#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;


int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<long long> weather(n+1);			// ���� ����
	vector<long long> accumulatesum(n+1);	// ���� ��

	for(int i = 1 ; i <= n ; ++i)
	{
		int temp;
		cin >> temp;
		weather[i] = temp;
		accumulatesum[i] = temp + accumulatesum[i - 1];	// ���� �� ����.
	}

	// ���� ��������..
	//vector<bool> combine(weather.size());
	//fill(combine.end() - k, combine.end(), true);	// ������ ����(k)��ŭ
	//vector<int> check;
	//do
	//{
	//	int mix = 0;
	//	for (int i = 0; i < weather.size(); ++i)
	//	{
	//		if (combine[i])
	//		{
	//			
	//			cout << weather[i] << " "; // Ȯ��
	//			mix += weather[i];
	//		}
	//	}
	//	cout << endl; // Ȯ��
	//	check.push_back(mix);
	//} while (next_permutation(combine.begin(), combine.end()));

	auto answer = LLONG_MIN;

	for (int i = k; i <= n; ++i)
		answer = max(answer, accumulatesum[i] - accumulatesum[i - k]);		// ���� �� Ȯ��

	cout << answer << endl;
}