#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

// 강의
int solution(int N, int number)
{
	int answer = -1;

	unordered_set<int> s[8];
	int base = 0;
	
	for (int i = 0; i < 8; ++i)
	{
		base = 10 * base + 1;
		s[i].insert(base * N);	// N번 연달아 썼을때 만들어지는 수 부터 넣어놓는다. // 5, 55, 555 ...
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			for (auto& op1 : s[j])	// 왼쪽. A * B 에서 A
			{
				for (auto& op2 : s[i - j - 1])	// 오른쪽. A * B 에서 B 
				{
					// 사칙연산들 해준다.
					s[i].insert(op1 + op2);
					s[i].insert(op1 - op2);
					s[i].insert(op1 * op2);
					if(op2 != 0)
						s[i].insert(op1 / op2);	
				}
			}
		}

		if (s[i].count(number) > 0)
		{
			answer = i + 1;
			break;
		}
	}

	return answer;
}