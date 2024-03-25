#include <iostream>
#include <limits>
#include <vector>
#include <queue>

#define INF numeric_limits<int>::max()
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e, start = 0;
	cin >> v >> e >> start;

	//vector<vector<int>> edge(v + 1, vector<int>(v + 1, INF));	// 간선 배열
	vector<pair<int, int>> edge[20001]; // 간선 배열
	//vector<bool> visit(v + 1, false);	// 방문 배열
	vector<int> dist(v + 1, INF);		// 노드 방문 비용 배열

	for (int i = 0; i < e; ++i)
	{
		int u, v, w = 0;
		cin >> u >> v >> w;
		edge[u].push_back(make_pair(w, v));	// 거리, 노드
	}

	priority_queue<pair<int, int>> pq;	// 거리, 노드

	pq.push(make_pair(0, start));	// 시작점의 거리는 0
	dist[start] = 0;				// 시작점의 거리는 0

	// dijkstra
	while (!pq.empty())
	{
		auto distance = -pq.top().first;
		auto node = pq.top().second;
		pq.pop();

		if (dist[node] < distance)
			continue;

		for (int i = 0; i < edge[node].size(); ++i)
		{
			auto distance_check = distance + edge[node][i].first;
			if (distance_check < dist[edge[node][i].second])	// 비용 작으면 갱신
			{
				dist[edge[node][i].second] = distance_check;
				pq.push(make_pair(-distance_check, edge[node][i].second));
			}
		}
	}

	for (int i = 1; i <= v; ++i)
	{
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}

}