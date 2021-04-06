#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str, boom;
	cin >> str >> boom;

	//int idx = str.find(boom);
	//while (idx != string::npos)	// 폭발 문자열이 있으면
	//{
	//	// 뒤와 앞을 이어준다.
	//	str =  str.substr(0, idx)+ str.substr(idx + boom.length(), str.length());
	//	idx = str.find(boom);
	//}
	stack<char> s1;
	stack<char> s2;

	for (int i = 0; i < str.length(); ++i)
		s1.push(str[i]);

	string cmp;
	while (true)
	{
		s2.push(s1.top());
		cmp = cmp + s1.top();
	}

	

	if (str.empty())
		cout << "FRULA" << endl;
	else
		cout << str << endl;
}