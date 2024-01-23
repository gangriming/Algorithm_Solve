#include <iostream>
#include <map>

using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, string> score;

	// 흠~~~~ 스위치 케이스말고 뭐 좋은게있나 어짜피 똑같을 거 같은데.
	score.emplace(make_pair("A+", "4.3"));
	score.emplace(make_pair("A0", "4.0"));
	score.emplace(make_pair("A-", "3.7"));
	score.emplace(make_pair("B+", "3.3"));
	score.emplace(make_pair("B0", "3.0"));
	score.emplace(make_pair("B-", "2.7"));
	score.emplace(make_pair("C+", "2.3"));
	score.emplace(make_pair("C0", "2.0"));
	score.emplace(make_pair("C-", "1.7"));
	score.emplace(make_pair("D+", "1.3"));
	score.emplace(make_pair("D0", "1.0"));
	score.emplace(make_pair("D-", "0.7"));
	score.emplace(make_pair("F", "0.0"));

	string str;
	cin >> str;
	
	cout << score[str] << endl;
}