#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	vector<string> participant;
	vector<string> completion;
	string temp;

	for (int i = 0; i < 5; ++i)
	{
		cin >> temp;
		participant.push_back(temp);
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> temp;
		completion.push_back(temp);
	}


	unordered_map<string, int> runner;	// 해시 테이블 
	//// 참여자를 담고 
	//for (auto& value : participant)
	//	runner[value]++;

	//// 완주자를 빼고
	//for (auto& value : completion)
	//	runner[value]--;

	//// 못한사람 출력.
	//for (auto& value : runner)
	//{
	//	if (value.second > 0)
	//		cout << value.first << endl;
	//}
	//// 리니어 타임의 복잡도... (강의)


	// 다른 좋은 방법중 하나는, 정렬.
	// 두개를 정렬해서, 같은 인덱스인데 다른것이 나오면, 그게 완주하지 못한 사람.
	sort(participant.begin(), participant.end());
	sort(completion.begin(), completion.end());

	for (int i = 0; i < completion.size(); ++i)
	{
		if (participant[i] != completion[i])
		{
			cout << participant[i] << endl;
			return 0;
		}
	}
	// 여기까지 온다면
	cout << participant[participant.size() - 1] << endl;

	return 0;
}