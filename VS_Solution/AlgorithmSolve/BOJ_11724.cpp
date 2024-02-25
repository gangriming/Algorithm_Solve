#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> graph[1001];		// ������
vector<bool> visit;

void dfs(int check)
{
	visit[check] = true;

	// ������ ����� ������ �湮�Ȱ� ������ Ȯ���غ���.
	for (auto& node : graph[check])
	{
		// �湮 �������� �̰͵� Ÿ�� ��.
		if (visit[node] == false)
			dfs(node);	
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	// �湮 ǥ�⸦ ��� �ұ�...
	//unordered_map<int, vector<int>> graph; <- �̰� �ܹ����϶� ���ٰ� ��.

	visit.assign(1001, false);

	while (m--)
	{
		int u, v;
		cin >> u >> v;

		// �������̶� �Ѵ� �־��ش�.
		//graph[u] = v;		// �䷡�ϸ� �� ��忡 �������� ������ ������ ����������
		//graph[v] = u;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int connect = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!visit[i])
		{
			// �湮���� ���� ���̸�, ���⼭���� ���ἱ���� �� üũ�ϸ鼭 �湮�Ѵ�.
			connect++;
			dfs(i);
		}
	}
	cout << connect << endl;
}