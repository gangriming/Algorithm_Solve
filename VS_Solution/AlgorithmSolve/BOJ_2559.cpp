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

	vector<long long> weather(n+1);			// 날씨 벡터
	vector<long long> accumulatesum(n+1);	// 누적 합

	for(int i = 1 ; i <= n ; ++i)
	{
		int temp;
		cin >> temp;
		weather[i] = temp;
		accumulatesum[i] = temp + accumulatesum[i - 1];	// 누적 값 더함.
	}

	// 조합 문제인줄..
	//vector<bool> combine(weather.size());
	//fill(combine.end() - k, combine.end(), true);	// 조합할 숫자(k)만큼
	//vector<int> check;
	//do
	//{
	//	int mix = 0;
	//	for (int i = 0; i < weather.size(); ++i)
	//	{
	//		if (combine[i])
	//		{
	//			
	//			cout << weather[i] << " "; // 확인
	//			mix += weather[i];
	//		}
	//	}
	//	cout << endl; // 확인
	//	check.push_back(mix);
	//} while (next_permutation(combine.begin(), combine.end()));

	auto answer = LLONG_MIN;

	for (int i = k; i <= n; ++i)
		answer = max(answer, accumulatesum[i] - accumulatesum[i - k]);		// 구간 합 확인

	cout << answer << endl;
}