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


	unordered_map<string, int> runner;	// �ؽ� ���̺� 
	//// �����ڸ� ��� 
	//for (auto& value : participant)
	//	runner[value]++;

	//// �����ڸ� ����
	//for (auto& value : completion)
	//	runner[value]--;

	//// ���ѻ�� ���.
	//for (auto& value : runner)
	//{
	//	if (value.second > 0)
	//		cout << value.first << endl;
	//}
	//// ���Ͼ� Ÿ���� ���⵵... (����)


	// �ٸ� ���� ����� �ϳ���, ����.
	// �ΰ��� �����ؼ�, ���� �ε����ε� �ٸ����� ������, �װ� �������� ���� ���.
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
	// ������� �´ٸ�
	cout << participant[participant.size() - 1] << endl;

	return 0;
}