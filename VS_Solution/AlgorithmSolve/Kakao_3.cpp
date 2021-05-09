#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
	string answer = "";

	vector<int> v(n, 1);	// 1 ���� -1 ������
	stack<int> s;
	int sel = k;

	for (int i = 0; i < cmd.size(); ++i)
	{
		// Select
		if (cmd[i][0] == 'D')
		{
			int temp = atoi(cmd[i].substr(2, cmd[i].length()).c_str());
			while (temp > 0)
			{
				sel++;
				if (v[sel] == 1)
					temp--;
			}
			if (sel > n)
				sel = n - 1;
		}
		else if (cmd[i][0] == 'U')
		{
			int temp = atoi(cmd[i].substr(2, cmd[i].length()).c_str());
			while (temp > 0)
			{
				sel--;
				if (v[sel] == 1)
					temp--;
			}
			if (sel < 0)
				sel = 0;
		}

		// Modifi
		if (cmd[i][0] == 'C')	// ����
		{
			v[sel] = -1;
			s.push(sel);
			if (sel >= n - 1)	// ������ ���̶��
				sel--;
			else
				sel++;
		}
		else if (cmd[i][0] == 'Z')	// �ǵ�����
		{
			if (!s.empty())
			{
				v[s.top()] = 1;
				//if (s.top() < sel)
				//	sel++;
				s.pop();
			}
		}
	}
	
	for (const auto value : v)
	{
		if (value == 1)
			answer += "O";
		else
			answer += "X";
	}
	return answer;
}

int main()
{
	// ǥ �ళ��, ó�� ���õ� �� ��ġ, ���� ���
	solution(8, 2, vector<string>{"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"});
	solution(8, 2, vector<string>{"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z", "U 1", "C"});
}