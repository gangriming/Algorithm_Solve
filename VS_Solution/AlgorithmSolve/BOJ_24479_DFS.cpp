#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<int> graph[], vector<bool>& visit)
{
	visit[node] = true;
	cout << node << "\n";

	bool novisit = false;
	for (auto& edge : graph[node])
	{
		if (visit[edge] == false)
		{
			novisit = true;
			dfs(edge, graph, visit);
		}
	}

	if (novisit == false)
		cout << "0\n";
}

// 이거 몽가.. 내가 문제부터 잘못 이해한거같음.

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;

	//vector<vector<int>> graph(n+1, vector<int>(n+1, 0));	// 메모리 초과
	vector<int> graph[100001];
	vector<bool> visit(100001, false);

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= 100000; ++i)
		sort(graph[i].begin(), graph[i].end());

	dfs(r, graph, visit);
	
}