#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector<int> graph[1001];		// 무방향
vector<bool> visit;

void dfs(int check)
{
	visit[check] = true;

	// 정점에 연결된 노드들이 방문된게 없는지 확인해본다.
	for (auto& node : graph[check])
	{
		// 방문 안했으면 이것도 타고 들어감.
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

	// 방문 표기를 어떻게 할까...
	//unordered_map<int, vector<int>> graph; <- 이건 단방향일때 쓴다고 함.

	visit.assign(1001, false);

	while (m--)
	{
		int u, v;
		cin >> u >> v;

		// 무방향이라서 둘다 넣어준다.
		//graph[u] = v;		// 요래하면 한 노드에 여러개의 간선이 있으면 씹히더라고요
		//graph[v] = u;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int connect = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (!visit[i])
		{
			// 방문하지 않은 점이면, 여기서부터 연결선들을 다 체크하면서 방문한다.
			connect++;
			dfs(i);
		}
	}
	cout << connect << endl;
}