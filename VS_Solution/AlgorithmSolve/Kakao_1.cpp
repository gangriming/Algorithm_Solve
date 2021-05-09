#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = 0;

	int idx = 0;
	while (idx < s.length())
	{
		if (s[idx] > 57) // 숫자가 아니라면
		{
			if (s.substr(idx, 4) == "zero")
				s.replace(idx, 4, "0");
			else if (s.substr(idx, 3) == "one")
				s.replace(idx, 3, "1");
			else if (s.substr(idx, 3) == "two")
				s.replace(idx, 3, "2");
			else if (s.substr(idx, 5) == "three")
				s.replace(idx, 5, "3");
			else if (s.substr(idx, 4) == "four")
				s.replace(idx, 4, "4");
			else if (s.substr(idx, 4) == "five")
				s.replace(idx, 4, "5");
			else if (s.substr(idx, 3) == "six")
				s.replace(idx, 3, "6");
			else if (s.substr(idx, 5) == "seven")
				s.replace(idx, 5, "7");
			else if (s.substr(idx, 5) == "eight")
				s.replace(idx, 5, "8");
			else if (s.substr(idx, 4) == "nine")
				s.replace(idx, 4, "9");
		}

		idx++;
	}

	return atoi(s.c_str());
}

int main()
{
	cout << solution("one4seveneight") << endl;
	cout << solution("23four5six7") << endl;
	cout << solution("2three45sixseven") << endl;
	cout << solution("123") << endl;
}